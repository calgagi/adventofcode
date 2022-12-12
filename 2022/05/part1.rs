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

    fn get_i64(&mut self) -> i64 {
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
}

// ===============================================
// main
fn main() {
    let mut scanner = Scanner::new();
    scanner.scan();

}
