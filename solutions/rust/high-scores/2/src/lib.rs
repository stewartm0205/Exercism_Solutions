#[derive(Debug)]
pub struct HighScores <'a>{
    scores: &'a[u32],
}

impl <'a>HighScores<'a> {
    pub fn new(scores: &[u32]) -> Self {
        let s = HighScores{all_score:&[u32;100], latest_score:None, highest_score:None, three_highest_scores:&[u32; 3],};
        s.all_score = scores;
        return s;
    }

    pub fn scores(&self) -> &[u32] {
        return self.all_score;
    }

    pub fn latest(&self) -> Option<u32> {
        return self.latest_score;
    }

    pub fn personal_best(&self) -> Option<u32> {
        return self.highest_score;
    }

    pub fn personal_top_three(&self) -> Vec<u32> {
        return self.three_highest_scores.to_vec();
    }
}
