from collections import defaultdict

class School(object):

    def __init__(self):
        self.school_roster=defaultdict(list)

    def add_student(self, name, grade):
        self.school_roster[grade].append(name)

    def roster(self):
        return([name for gradelist in (self.grade(grd) for grd in sorted(self.school_roster.keys())) for name in gradelist])

    def grade(self, grade_number):
        return(sorted(self.school_roster[grade_number]))
