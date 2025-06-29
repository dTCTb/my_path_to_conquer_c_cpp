struct Solution;

impl Solution {
    pub fn max_subsequence(nums: Vec<i32>, k: i32) -> Vec<i32> {
        type VtI32Usize = Vec<(i32, usize)>;
        let (len, k) = (nums.len(), k as usize);
        let mut n: VtI32Usize = nums
            .iter()
            .enumerate()
            .map(|(idx, &num)| (num, idx))
            .collect();
        n.sort_unstable();
        let mut n: VtI32Usize = n.into_iter().skip(len - k).collect();
        n.sort_unstable_by(|&l, &r| l.1.cmp(&r.1));
        n.into_iter().map(|(_, idx)| nums[idx]).collect()
    }
}

fn main() {}

#[cfg(test)]
mod tests {
    use super::Solution;
    #[test]
    pub fn testcases() {
        assert_eq!(vec![3, 3], Solution::max_subsequence(vec![2, 1, 3, 3], 2));
        assert_eq!(
            vec![-1, 3, 4],
            Solution::max_subsequence(vec![-1, -2, 3, 4], 3)
        );
        assert_eq!(vec![4, 3], Solution::max_subsequence(vec![3, 4, 3, 3], 2));
        assert_eq!(vec![50, -75], Solution::max_subsequence(vec![50, -75], 2));
    }
}
