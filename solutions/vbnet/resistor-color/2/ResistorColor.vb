Imports System

Public Module ResistorColor

    Public Function ColorCode(ByVal color As String) As Integer
        Select Case color
            Case "black"
                Return 0
            Case "brown"
                Return 1
            Case "red"
                Return 2
            Case "orange"
                Return 3
            Case "yellow"
                Return 4
            Case "green"
                Return 5
            Case "blue"
                Return 6
            Case "violet"
                Return 7
            Case "grey"
                Return 8
            Case "white"
                Return 9
        End Select
    End Function

    Public Function Colors() As String()
        Return {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"}
    End Function

End Module