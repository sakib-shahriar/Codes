
public class CurrentAccount extends BankAccount{

    String tradeLicenseNumber;


    public CurrentAccount(String memberName, double accountBalance, String tradeLicenseNumber)
    {
        super(memberName,accountBalance,5000);
        this.tradeLicenseNumber=tradeLicenseNumber;
    }
}
