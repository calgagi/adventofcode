use std::io;
use std::io::BufRead;
use std::collections::VecDeque;
use std::collections::BTreeMap;

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

fn priority(c: char) -> i32 {
    if (c as i32) <= ('z' as i32) && (c as i32) >= ('a' as i32) {
        return (c as i32) - ('a' as i32) + 1;
    }
    else {
        return (c as i32) - ('A' as i32) + 27;
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
    for s in sacks {
        let l = s.len();
        let mut m = BTreeMap::new();
        let mut i = 0;
        for c in s.chars() {
            if i < l/2 {
                if let Some(p) = m.get_mut(&c) { 
                    *p += 1;
                }
                else {
                    m.insert(c, 1);
                }
            }
            else {
                if let Some(p) = m.get_mut(&c) {
                    if *p > 0 {
                        *p = 0;
                        ans += priority(c);
                    }
                }
            }
            i += 1;
        }
    }

    println!("{}", ans);
}
