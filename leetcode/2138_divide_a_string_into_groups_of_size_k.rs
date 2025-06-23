struct Solution;

impl Solution {
    pub fn divide_string(s: String, k: i32, fill: char) -> Vec<String> {
        Self::divide_string_2(s, k, fill)
    }
    fn divide_string_1(s: String, k: i32, fill: char) -> Vec<String> {
        let k = k as usize;
        s.as_bytes()
            .chunks(k)
            .filter_map(|chunk| {
                let mut group = Vec::from(chunk);
                if chunk.len() < k {
                    for _ in 0..(k - chunk.len()) {
                        group.push(fill as u8);
                    }
                }
                String::from_utf8(group).ok()
            })
            .collect::<Vec<String>>()
    }
    fn divide_string_2(s: String, k: i32, fill: char) -> Vec<String> {
        let (k, fill) = (k as usize, fill as u8);
        s.as_bytes()
            .chunks(k)
            .filter_map(|chunk| {
                let mut group = Vec::from(chunk);
                String::from_utf8(match k - chunk.len() {
                    0 => group,
                    diff => {
                        group.extend(vec![fill; diff]);
                        group
                    }
                })
                .ok()
            })
            .collect::<Vec<String>>()
    }
}

fn main() {
    let run = |x, y, z| Solution::divide_string(x, y, z);
    println!("{:?}", run("abcdefghi".to_string(), 3, 'x'));
    println!("{:?}", run("abcdefghij".to_string(), 3, 'x'));
}
