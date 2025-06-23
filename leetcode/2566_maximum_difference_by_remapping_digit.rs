struct Solution;

impl Solution {
    pub fn min_max_difference(num: i32) -> i32 {
        let s = num.to_string();

        let max = (match s.chars().position(|x| x != '9') {
            Some(idx) => s.replace(s.chars().nth(idx).unwrap(), "9"),
            None => s.clone(),
        })
        .parse::<i32>()
        .unwrap();

        let min = s
            .replace(s.chars().next().unwrap(), "0")
            .parse::<i32>()
            .unwrap();

        max - min
    }

    fn test(num: &[i32]) {
        for n in num {
            println!("{n: >8} - ans: {}", Self::min_max_difference(*n));
        }
    }
}

fn main() {
    Solution::test(&[11891, 90, 999, 7, 1001, 90817263, 54]);
    // ans:          99009, 99, 999, 9, 9009, 99000000, 90
}
