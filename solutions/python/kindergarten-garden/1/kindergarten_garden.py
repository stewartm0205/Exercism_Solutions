class Garden():
    default_students = ["Alice", "Bob", "Charlie", "David",
                      "Eve", "Fred", "Ginny", "Harriet",
                      "Ileana", "Joseph", "Kincaid", "Larry"]
    plant_names = {"V":"Violets", "R":"Radishes", 
                   "C":"Clover", "G":"Grass"}

    def __init__(self, diagram, students=None):
        self.diagram = diagram
        if students == None:
            self.students = self.default_students
        else:
            self.students = sorted(students)

    def plants(self, student):
        si = self.students.index(student)
        plant_rows = self.diagram.split("\n")
        plnts = [] 
        for row in range(0,2):
            for col in range(0,2):
                p = plant_rows[row][2*si+col:2*si+col+1]
                plnts.append(self.plant_names[p])
        return (plnts)  
