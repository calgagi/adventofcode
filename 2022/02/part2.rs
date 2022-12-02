use std::io;
use std::io::BufRead;

fn main() {
    let stdin = io::stdin();
    let mut handle = stdin.lock();
    let mut line = String::new();
    let mut eof = false;

    let mut ans: i32 = 0;

    while !eof {
        match handle.read_line(&mut line) {
            Ok(0) => {
                println!("{}", ans);
                eof = true;
            }
            Ok(_) => {
                line.pop();
                let u: i32 = (line.chars().nth(0).unwrap() as i32) - ('A' as i32);
                let mut v: i32 = (line.chars().nth(2).unwrap() as i32) - ('X' as i32);
                let mut win: i32 = 0;
                if v == 2 {
                    v = (u + 1i32) % 3i32;
                }
                else if v == 1 {
                    v = u;
                }
                else if v == 0 {
                    v = (u - 1i32 + 3i32) % 3i32;
                }

                if ((u + 1i32) % 3i32) == v {
                    win = 6;
                }
                else if u == v {
                    win = 3;
                }

                ans += win + (v + 1);

                line.clear();
            }
            Err(_) => todo!()
        }
    }
}
