#![allow(dead_code)]

struct Solution {
    s: String,
    part: String,
    ans: String,
}

impl Solution {
    pub fn remove_occurrences(s: String, part: String) -> String {
        Solution::my_solve(s, part)
    }

    /* O(kn) 0ms 2.55mb
     * I know I should use stack, but just wanna to
     * try out String method provided in Rust */
    pub fn my_solve(s: String, part: String) -> String {
        let mut ans = s.replacen(&part, "", 1);
        let mut tmp = String::with_capacity(s.len());
        while ans != tmp {
            tmp = ans.clone();
            ans = ans.replacen(&part, "", 1);
        }
        ans
    }

    pub fn learn_new_thing(s: String, part: String) -> String {
        let mut result = s;
        while let Some(pos) = result.find(&part) {
            result.replace_range(pos..pos + part.len(), "");
        }
        result
    }

    pub fn test(&self) {
        println!(r#"remove "{}" from "{}""#, self.part, self.s);
        let my_ans = Solution::remove_occurrences(self.s.clone(), self.part.clone());
        match my_ans == self.ans {
            true => print!("  Correct! "),
            _ => print!("  Incorrect! "),
        }
        println!(r#"ans: "{}""#, self.ans);
        println!();
    }
}

fn main() {
    let tc1 = Solution {
        s: "daabcbaabcbc".to_string(),
        part: "abc".to_string(),
        ans: "dab".to_string(),
    };
    tc1.test();
    let tc2 = Solution {
        s: "axxxxyyyyb".to_string(),
        part: "xy".to_string(),
        ans: "ab".to_string(),
    };
    tc2.test();
    let tc3 = Solution {
        s: "aabababa".to_string(),
        part: "aba".to_string(),
        ans: "ba".to_string(),
    };
    tc3.test();
}
