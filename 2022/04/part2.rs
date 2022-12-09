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
        while !self.data.is_empty() {
            let c: char = *self.data.front().unwrap();
            if !(c == ' ' || c == '\n' || c == '\t') { break; }
            self.data.pop_front();
        }
    }

    fn get_i64(&mut self) -> i64 {
        let mut num_chars = Vec::new();
        while !self.data.is_empty() {
            let c: char = *self.data.front().unwrap();
            if c.is_digit(10) || (num_chars.is_empty() && c == '-') {
                num_chars.push(c);
            }
            else { break; }
            self.data.pop_front();
        }
        self.space();
        return (num_chars.iter().collect::<String>()).parse::<i64>().unwrap();
    }

    fn get_string(&mut self) -> String {
        let mut chars = Vec::new();
        while !self.data.is_empty() {
            let c: char = *self.data.front().unwrap();
            if c == ' ' || c == '\n' || c == '\t' { break; }
            chars.push(c);
            self.data.pop_front();
        }
        self.space();
        return chars.iter().collect::<String>();
    }
    
    fn get_char(&mut self) -> char {
        if !self.data.is_empty() {
            let c = *self.data.front().unwrap();
            self.data.pop_front();
            return c;
        }
        return '~';
    }

    fn is_empty(&self) -> bool {
        return self.data.is_empty();
    }
}

// ===============================================
// main
fn main() {
    let mut scanner = Scanner::new();
    scanner.scan();

    let mut ans = 0;
    while !scanner.is_empty() {
        let mut a = scanner.get_i64();
        scanner.get_char();
        let mut b = scanner.get_i64();
        scanner.get_char();
        let mut c = scanner.get_i64();
        scanner.get_char();
        let mut d = scanner.get_i64();

        if a > c || (a == c && b < d) {
            std::mem::swap(&mut a, &mut c);
            std::mem::swap(&mut b, &mut d);
        }

        if !(a > d || b < c) {
            ans += 1;
        }
    }

    println!("{}", ans);
}
