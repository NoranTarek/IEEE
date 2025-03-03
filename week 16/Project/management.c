
void Tload_data()
 {
    Tclear_list();
    FILE *file = fopen("Transactions.csv", "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
    }
    else
    {
        char line[200];
        while (fgets(line, sizeof(line), file)) {
        Transaction *newTransaction = (Transaction *)malloc(sizeof(Transaction));
        if (newTransaction == NULL) {
            printf("Memory allocation failed.\n");
        }
        else
        {
            sscanf(line, "%99[^,],%99[^,],%d\n", newTransaction->sender, newTransaction->receiver, &newTransaction->amount);
            newTransaction->next = Thead;
            Thead = newTransaction;
        }
    }
    fclose(file);

    }
}
