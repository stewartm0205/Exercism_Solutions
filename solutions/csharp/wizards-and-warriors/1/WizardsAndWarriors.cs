using System;

abstract class Character
{
    string characterType;
    bool vulnerable;
    protected Character(string characterType)
    {
        this.characterType = characterType;
        this.vulnerable = false;
    }

    public abstract int DamagePoints(Character target);

    public virtual bool Vulnerable()
    {
        return vulnerable;
    }

    public override string ToString()
    {
        return "Character is a " + this.characterType;
    }
}

class Warrior : Character
{
    public Warrior() : base("Warrior")
    {
    }

    public override int DamagePoints(Character target)
    {
        if (target is Wizard & target.Vulnerable()) return 10;
        return 6;
    }
}

class Wizard : Character
{

    bool preparedSpell;
    public Wizard() : base("Wizard")
    {
        preparedSpell = false;
    }

    public override int DamagePoints(Character target)
    {
        if (preparedSpell) return 12;
        return 3;
    }

    public void PrepareSpell()
    {
        preparedSpell = true;
    }

    public override bool Vulnerable()
    {
        if (!preparedSpell) return true;
        return base.Vulnerable();
    }

}
