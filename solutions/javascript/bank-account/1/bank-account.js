//
// This is only a SKELETON file for the 'Bank Account' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export class BankAccount {
  constructor() {
    this.close();
  }

  open() {
    if (this.status == 'open') throw new ValueError;
    this.status='open';
    this.amount = 0;
  }

  close() {
    if (this.status == 'closed') throw new ValueError;
    this.status = 'closed';
    this.amount=0;
  }

  deposit(amount) {
    if (amount < 0) throw new ValueError;
    if (this.status == 'open') this.amount += amount;
    else throw new ValueError;
  }

  withdraw(amount) {
    if (amount < 0) throw new ValueError;
    if (this.status == 'open' && this.amount >= amount) this.amount -= amount;
    else throw new ValueError;
  }

  get balance() {
    if (this.status == 'closed') throw new ValueError;
    var ret = this.amount;
    return ret;
  }
}

export class ValueError extends Error {
  constructor() {
    super('Bank account error');
  }
}
