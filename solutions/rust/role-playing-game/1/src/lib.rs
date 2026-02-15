// This stub file contains items which aren't used yet; feel free to remove this module attribute
// to enable stricter warnings.
#![allow(unused)]

pub struct Player {
    pub health: u32,
    pub mana: Option<u32>,
    pub level: u32,
}

impl Player {
    pub fn revive(&self) -> Option<Player> {
        if self.health <= 0 {
            if self.level >= 10 {
                return Some(Player {health:100, mana: Some(100), level: self.level});
            } else {
                return Some(Player {health:100, mana: None, level: self.level});
            }
        } else {
            return None;
        }
    }

    pub fn cast_spell(&mut self, mana_cost: u32) -> u32 {
        let tmana  = self.mana.unwrap_or(0);

        if tmana == 0 {
            if mana_cost > self.health {
                self.health = 0;
            } else {
                self.health -= mana_cost;
            }
            return 0;
        }
        else {
            if tmana < mana_cost {
                return 0;
            } else {
                self.mana = Some(tmana - mana_cost);
                return 2 * mana_cost;
            }
        }
    }
}
