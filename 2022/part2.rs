use std::io;
use std::io::BufRead;

fn main() {
    let stdin = io::stdin();
    let mut handle = stdin.lock();
    let mut line = String::new();
    let mut eof = false;

    let mut vec = Vec::new();
    let mut val: i32 = 0;

    while !eof {
        match handle.read_line(&mut line) {
            Ok(0) => {
                vec.sort();
                let mut ans: i32 = 0;
                for i in vec.len()-3..vec.len() {
                    ans += vec[i];
                }
                println!("{}", ans);
                eof = true;
            }
            Ok(_) => {
                line.pop();
                if line.eq("") {
                    vec.push(val);
                    val = 0;
                }
                else {
                    let len = line.parse::<i32>().unwrap();
                    val += len;
                }
                line.clear();
            }
            Err(_) => todo!()
        }
    }
}
