struct Solution;

impl Solution {
    pub fn max_ascending_sum(nums: Vec<i32>) -> i32 {
        Solution::learn_new_thing(nums)
    }

    /* O(n+k) 0ms 2.23mb */
    fn my_solve(nums: Vec<i32>) -> i32 {
        let mut ans: Vec<i32> = Vec::new();
        let mut tmp: i32 = nums[0];
        for sub in nums.windows(2) {
            match sub[0] < sub[1] {
                true => tmp += sub[1],
                false => {
                    ans.push(tmp);
                    tmp = sub[1];
                }
            }
        }
        ans.push(tmp);
        let mut max = ans[0];
        for n in ans {
            max = std::cmp::max(n, max);
        }
        println!("{max}");
        max
    }

    fn learn_new_thing(nums: Vec<i32>) -> i32 {
        let ans = nums
            .into_iter()
            .fold((0, 0, None::<i32>), |(max, run, last), cur| {
                /* at the beginning, last initialize in None::<i32> */
                /* some below code are ran at the first time */
                let Some(last) = last else {
                    return (cur, cur, Some(cur));
                };

                if last < cur {
                    let run = run + cur;
                    (max.max(run), run, Some(cur))
                } else {
                    let run = cur;
                    (max.max(run), run, Some(cur))
                }
            })
            .0;
        println!("{ans}");
        ans
    }
}

pub fn main() {
    Solution::max_ascending_sum(vec![10, 20, 30, 5, 10, 50]);
    Solution::max_ascending_sum(vec![10, 20, 30, 40, 50]);
    Solution::max_ascending_sum(vec![12, 17, 15, 13, 10, 11, 12]);
    Solution::max_ascending_sum(vec![3, 6, 10, 1, 8, 9, 9, 8, 9]); // 19
}
