use std::io;
use std::io::BufRead;
use std::collections::VecDeque;

// ===============================================
// Scanner 
struct Scanner {
    data: VecDeque<char>,
}
impl Scanner {
    fn scan(&mut self) {
        let stdin = io::stdin();
        let handle = stdin.lock();
        for line in handle.lines() {
            let s: String = line.unwrap();
            for c in s.chars() {
                self.data.push_back(c);
            }
            self.data.push_back('\n');
        }
    }

    fn new() -> Scanner {
        Scanner { data: VecDeque::new() }
    }

    fn space(&mut self) {
        while let Some(c) = self.try_get_char() {
            if !matches!(c, ' ' | '\n' | '\t') { break; }
            self.data.pop_front();
        }
    }

    fn get_int(&mut self) -> usize {
        let mut ans: String = String::from("");
        while let Some(c) = self.try_get_char() {
            if !(c.is_digit(10) || (ans.len() == 0 && c == '-')) { break; }
            ans.push(c);
            self.data.pop_front();
        }
        self.space();
        return ans.parse().unwrap();
    }

    fn get_string(&mut self) -> String {
        let mut ans: String = String::from("");
        while let Some(c) = self.try_get_char() {
            if matches!(c, ' ' | '\n' | '\t') { break; }
            ans.push(c);
            self.data.pop_front();
        }
        self.space();
        return ans;
    }
    
    fn try_get_char(&mut self) -> Option<char> { return self.data.front().copied(); }

    fn get_char(&mut self) -> char { return self.try_get_char().unwrap(); }

    fn get_line(&mut self) -> String {
        let mut ans: String = String::from("");
        while let Some(c) = self.try_get_char() {
            self.data.pop_front();
            if matches!(c, '\n') { break; }
            ans.push(c);
        }
        return ans;
    }

    fn is_empty(&self) -> bool { return self.data.is_empty(); }
}



// ===============================================
// main
fn main() {
    let mut scanner = Scanner::new();
    scanner.scan();

    let s = scanner.get_line();
    let mut ans = 0;
    let mut seen = vec!(0; 26);
    let mut q = VecDeque::new();
    for c in s.chars() {
        ans += 1;
        seen[(c as usize) - ('a' as usize)] += 1;
        q.push_back((c as usize) - ('a' as usize));
        if ans >= 5 {
            seen[q.pop_front().unwrap()] -= 1;
        }
        if ans >= 4 {
            let mut count = 0;
            for i in 0..26 {
                count += if seen[i] > 0 { 1 } else { 0 };
            }
            if count == 4 {
                break;
            }
        }
    }

    println!("{}", ans);
}
