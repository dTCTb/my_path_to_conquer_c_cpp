struct Solution;

impl Solution {
    pub fn are_almost_equal(s1: String, s2: String) -> bool {
        Solution::my_solve(s1, s2)
    }

    fn test(s1: &str, s2: &str) {
        println!("s1: {:#?} | s2: {:#?}", &s1, s2);
        println!(
            "ans: {}\n",
            Solution::learn_new_thing(s1.to_string(), String::from(s2))
        );
    }

    fn my_solve(s1: String, s2: String) -> bool {
        let mut vec: Vec<usize> = Vec::with_capacity(2);
        let s = if s1.len() == s2.len() {
            s1.len()
        } else {
            return false;
        };

        (0..s).for_each(|i| {
            if s1.chars().nth(i).unwrap() != s2.chars().nth(i).unwrap() {
                vec.push(i);
            }
        });

        vec.is_empty()
            || vec.len() == 2
                && s1.chars().nth(vec[0]) == s2.chars().nth(vec[1])
                && s1.chars().nth(vec[1]) == s2.chars().nth(vec[0])
    }

    fn learn_new_thing(s1: String, s2: String) -> bool {
        let diff = s1
            .into_bytes()
            .into_iter()
            .zip(s2.into_bytes())
            .filter(|(a, b)| a != b)
            .collect::<Vec<_>>();

        diff.is_empty() || diff.len() == 2 && (diff[0].0, diff[0].1) == (diff[1].1, diff[1].0)
    }
}

pub fn main() {
    Solution::test("bank", "kanb");
    Solution::test("attack", "defend");
    Solution::test("kelb", "kelb");
}
