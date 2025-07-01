use std::collections::BTreeMap;

struct Solution;

impl Solution {
    pub fn find_lhs(mut nums: Vec<i32>) -> i32 {
        let mut map = BTreeMap::<i32, i32>::new();
        // nums.sort_unstable();
        nums.into_iter().for_each(|num| {
            *map.entry(num).or_default() += 1;
        });

        map.iter()
            .zip(map.iter().skip(1))
            .collect::<Vec<_>>()
            .into_iter()
            .fold(0, |max, ((&k1, &v1), (&k2, &v2))| {
                if k1.abs_diff(k2) == 1 {
                    max.max(v1 + v2)
                } else {
                    max
                }
            })
    }
}

fn main() {}

#[cfg(test)]
mod test {
    use super::*;
    #[test]
    fn testcases() {
        assert_eq!(Solution::find_lhs(vec![1, 3, 2, 2, 5, 2, 3, 7]), 5);
        assert_eq!(Solution::find_lhs(vec![1, 2, 3, 4]), 2);
        assert_eq!(Solution::find_lhs(vec![1, 1, 1, 1]), 0);
        assert_eq!(Solution::find_lhs(vec![1, 3, 5, 7, 9, 11, 13, 15, 17]), 0);
        assert_eq!(Solution::find_lhs(vec![1, 2, 2, 1]), 4);
    }
}
