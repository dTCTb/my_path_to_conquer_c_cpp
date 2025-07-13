#![allow(dead_code, unused_imports)]

struct Solution;
impl Solution {
    pub fn match_players_and_trainers(mut players: Vec<i32>, mut trainers: Vec<i32>) -> i32 {
        players.sort_unstable();
        trainers.sort_unstable();
        let (mut p_idx, mut ans) = (0_usize, 0);

        for trainer in trainers.into_iter() {
            if p_idx >= players.len() {
                break;
            }
            if trainer < players[p_idx] {
                continue;
            }
            p_idx += 1;
            ans += 1;
        }
        ans
    }
}

fn main() {
    use crate::Solution as S;
    // cargo test --bin <name>
    // cargo eval --test -- path/to/this/file.rs
}

#[rustfmt::skip]
#[cfg(test)]
mod testcases {
    use super::Solution as S;
    #[test]
    fn randoms() {
        assert_eq!(S::match_players_and_trainers(vec![4, 7, 9], vec![8, 2, 5, 8]), 2);
        assert_eq!(S::match_players_and_trainers(vec![9, 1, 3, 4, 2, 1], vec![5, 5, 3, 1]), 4);
    }
    #[test]
    fn one_player_one_trainer() {
        assert_eq!(S::match_players_and_trainers(vec![2], vec![1]), 0);
        assert_eq!(S::match_players_and_trainers(vec![1], vec![2]), 1);
    }
    #[test]
    fn many_players_one_trainer() {
        assert_eq!(S::match_players_and_trainers(vec![1, 1, 1], vec![10]), 1);
    }
    #[test]
    fn one_player_many_trainers() {
        assert_eq!(S::match_players_and_trainers(vec![1], vec![3,3,2,1]), 1);
    }
    #[test]
    fn same_players_trainers() {
        assert_eq!(S::match_players_and_trainers(vec![3,3,3,3], vec![3,3,3,3]), 4);
    }
}
