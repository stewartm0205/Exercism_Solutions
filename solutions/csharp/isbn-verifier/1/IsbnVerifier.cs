using System;

public static class IsbnVerifier
{
    public static bool IsValid(string number)
    {
        int mult=10;
        int s=0;
        number = number.Replace("-","");
        if (number.Length<10 || number.Length>10) return false;
        foreach (char ch in number){
            if (ch>='0' && ch <='9') {
                s+=mult*(ch-'0');
                mult--;
            } else if (ch == 'X') {
                s+=10;
            } else if (ch != '-') {
                return false;
            }
        }
        if (s % 11 == 0) return true;
        return false;
        //throw new NotImplementedException("You need to implement this function.");
    }
}