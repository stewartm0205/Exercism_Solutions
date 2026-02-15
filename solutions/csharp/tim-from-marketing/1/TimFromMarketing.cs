using System;

static class Badge
{
    public static string Print(int? id, string name, string? department)
    {
        string ret = "";
        if (id != null) ret += $"[{id}] - ";
        ret += name + " - ";
        if (department == null) ret += "OWNER";
        else ret += department.ToUpper();
        return ret;
    }
}
