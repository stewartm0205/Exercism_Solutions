class School(object):
    def __init__(self):
        self.school_roster={}

    def add_student(self, name, grade):
        if grade in self.school_roster:
            self.school_roster[grade].append(name)
        else:
            self.school_roster[grade] = []
            self.school_roster[grade].append(name)

    def roster(self):
        all_names = []
        grades = sorted(self.school_roster.keys())
        for grade in grades:
            all_names = all_names + self.grade(grade)
        return(all_names)

    def grade(self, grade_number):
        names = []
        if grade_number in self.school_roster:
            names = self.school_roster[grade_number]
        return(sorted(names))
