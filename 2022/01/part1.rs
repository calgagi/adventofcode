#[allow(unused_macros)]
macro_rules! read {
    ($out:ident as $type:ty) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A String");
        let $out = inner.trim().parse::<$type>().expect("Parsable");
    };
}
 
#[allow(unused_macros)]
macro_rules! read_str {
    ($out:ident) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A String");
        let $out = inner.trim();
    };
}
 
#[allow(unused_macros)]
macro_rules! read_vec {
    ($out:ident as $type:ty) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).unwrap();
        let $out = inner
            .trim()
            .split_whitespace()
            .map(|s| s.parse::<$type>().unwrap())
            .collect::<Vec<$type>>();
    };
}

use std::io::{self, BufRead};
use std::cmp;
 
fn main() {
    let stdin = io::stdin();
    let mut lines = stdin.lock().lines();
    let mut val: i32 = 0;
    let mut ans: i32 = 0;

    while let Some(line) = lines.next() {
        let length: i32 = line.unwrap().trim().parse().unwrap();

        for _ in 0..length {
            let line = lines
                .next()
                .expect("there was no next line")
                .expect("the line could not be read");

            if line.eq("") {
                val = 0;
            }
            else {
                val += line.parse::<i32>().unwrap();
            }
            ans = cmp::max(val, ans);
            println!("{}", ans);
        }
    }

}

