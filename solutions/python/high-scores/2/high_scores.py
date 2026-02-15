class HighScores(object):
    def __init__(self, scores):
        self.scores = scores

    def latest(self):
        return self.scores[-1]

    def highest(self):
        return sorted(self.scores, reverse=True)[0]

    def top(self):
        return sorted(self.scores, reverse=True)[0:3]

    def report(self):
        if self.latest() == self.highest():
            rpt_line = "Your latest score was " +  str(self.latest()) + ". That's your personal best!"
        else:
            rpt_line = "Your latest score was " +  str(self.latest()) + ". That's " + \
            str(self.highest() - self.latest()) + " short of your personal best!"

        return rpt_line


