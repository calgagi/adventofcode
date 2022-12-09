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

    fn is_empty(&self) -> bool {
        return self.data.is_empty();
    }
}

fn priority(c: char) -> usize {
    if (c as usize) <= ('z' as usize) && (c as usize) >= ('a' as usize) {
        return (c as usize) - ('a' as usize) + 1;
    }
    else {
        return (c as usize) - ('A' as usize) + 27;
    }
}

// ===============================================
// main
fn main() {
    let mut scanner = Scanner::new();
    scanner.scan();

    let mut sacks = Vec::new();
    while !scanner.is_empty() {
        sacks.push(scanner.get_string());
    }

    let mut ans = 0;
    let mut vs = vec![vec![false; 52]; 3];
    let mut counter = 0;
    for s in sacks {
        for c in s.chars() {
            vs[counter % 3][priority(c) - 1] = true;
        }
        counter += 1;
        if counter == 3 {
            for i in 0..52 {
                if vs[0][i] && vs[1][i] && vs[2][i] {
                    ans += i + 1;
                    break;
                }
            }
            counter = 0;
            vs = vec![vec![false; 52]; 3];
        }
    }

    println!("{}", ans);
}
