struct Solution;

impl Solution {
    pub fn clear_digits(s: String) -> String {
        let mut ans = String::with_capacity(s.len());
        s.chars().for_each(|x| {
            if x.is_ascii_digit() && !ans.is_empty() {
                ans.pop();
            } else {
                ans.push(x);
            }
        });
        ans
    }

    pub fn test(s: &str, ans: &str) {
        println!("{}", s);
        let my_ans = Solution::clear_digits(s.to_string());
        match my_ans == ans {
            true => print!("\tCorrect "),
            _ => print!("\tIncorrect "),
        }
        println!("ans: {ans}");
    }
}

pub fn main() {
    Solution::test("abc", "abc");
    Solution::test("cb34", "");
    Solution::test("a", "a");
    Solution::test("xzuzr2ghilydk", "xzuzghilydk");
    Solution::test(
        "qm93xjkpaaovhqckjhg5j1o4rndtg3bobgeke",
        "xjkpaaovhqckjhrndtbobgeke",
    );
    Solution::test(
        "pl5v0jttxe9acvd0t9vtxwrhvwajpasfe2nhtws48pweam4vsomd79nw14ed",
        "pjttxacvvtxwrhvwajpasfnhtpweavsoed",
    );
    Solution::test(
        "rrytkz6w5qwniszr6duuec0lqbeds3qdbzimoszqwxng5c02vxse03hpoarbu",
        "rrytkqwniszduuelqbedqdbzimoszqwxvxhpoarbu",
    );
    Solution::test(
        "wezofxhb44upfwyci72gbi2jwdxxank64yxvr677aegwl7jzgqlof4z9neisjq88pj1pvq98q",
        "wezofxupfwygbjwdxxayaegwjzgqloneisppq",
    );
    Solution::test(
        "g8dsianl4u49d3froonbnkrw83qzmdbh114lidlc2bv95s2pzwzuimi3ef443txu5d6h8ng5j5stu32y",
        "dsiafroonbnkqzmlidlpzwzuitxnsy",
    );
    Solution::test("sl2yqa6z8i0eqyqnla250rh8olipeu4oie5t16n8p2n67e391n01s7ol11qg93u6tuoy55no117861sj4wfno27p65212", "syqeqyq");
}
