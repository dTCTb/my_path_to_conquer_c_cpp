// 2200. Find All K-Distant Indices in an Array
struct Solution;
impl Solution {
    pub fn find_k_distant_indices(nums: Vec<i32>, key: i32, k: i32) -> Vec<i32> {
        let k = k as usize;
        let ki = nums
            .iter()
            .enumerate()
            .filter_map(|(i, &x)| if x == key { Some(i) } else { None })
            .collect::<Vec<usize>>();
        nums.into_iter()
            .enumerate()
            .filter_map(|(i, _)| {
                if ki.iter().any(|ki| ki.abs_diff(i) <= k) {
                    Some(i as i32)
                } else {
                    None
                }
            })
            .collect::<Vec<i32>>()
    }
}

fn main() {
    // #[cfg(test)]
    // mod lc_2200 {
    //     use super::Solution;
    //     #[test]
    //     pub fn testcases() {
    assert_eq!(
        Solution::find_k_distant_indices(vec![3, 4, 9, 1, 3, 9, 5], 9, 1),
        vec![1, 2, 3, 4, 5, 6]
    );
    assert_eq!(
        Solution::find_k_distant_indices(vec![2, 2, 2, 2, 2], 2, 2),
        vec![0, 1, 2, 3, 4]
    );
    //     }
    // }
}
