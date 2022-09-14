//Timothy McGowan
//ATM Function Header File
//CS345-81
int deposit(int balance,int amount){    //Requires a balance integer and an amount integer
        int newbaldep;                  //Initialize return variable
        printf("\n$%d has been added to your account \n",amount);
        newbaldep = (balance + amount); //Calculate New Balance
        printf("New Balance: $%d\n\n",newbaldep);   //Display New Balance to User
        return(newbaldep); //Return New balance to function call
}

int withdraw(int balance,int amount){   //Requires a balance integer and an amount integer
    int newbalance = (balance - amount);//Calculate New Balance
    printf("\n$%d has been withdrawn from your account \nNew Balance: $%d\n\n",amount,newbalance);//Display New Balance to User
    return(newbalance);//Return New balance to function call

}
