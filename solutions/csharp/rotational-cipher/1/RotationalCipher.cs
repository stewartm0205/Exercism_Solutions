using System;

public static class RotationalCipher
{
    public static string Rotate(string text, int shiftKey)
    {
        string cipher = "";
        int chi;
        foreach (char ch in text) {
            if (ch >= 'a' && ch <='z')
            {
                chi = 'a' + (ch + shiftKey - 'a') % 26;
                cipher += char.ConvertFromUtf32(chi);
            }
            else if (ch >= 'A' && ch <='Z') {
                chi = 'A' + (ch + shiftKey - 'A') % 26;
                cipher += char.ConvertFromUtf32(chi);
            }
            else cipher += char.ConvertFromUtf32(ch);
        }
        return cipher;
    }
}