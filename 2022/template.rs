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
}

// ===============================================
// main
fn main() {
    let mut s = Scanner::new();
    s.scan();

    println!("{}", s.get_i64());
    println!("{}", s.get_i64());
    println!("{}", s.get_i64());
}
