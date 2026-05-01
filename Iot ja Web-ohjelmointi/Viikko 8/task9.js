class BankAccount {
  constructor(owner, balance) {
    this.owner = owner;
    this.balance = balance;
  }
  deposit(amount) {
    this.balance += amount;
  }
  withdraw(amount) {
    if (this.balance >= amount) {
      this.balance -= amount;
    } else {
      console.log("Saldo ei riitä!");
    }
  }
}

const account = new BankAccount("Pekka", 1000);
account.deposit(500);
console.log(account.balance); 
account.withdraw(200);
console.log(account.balance);
account.withdraw(2000);