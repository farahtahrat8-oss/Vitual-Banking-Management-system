#include <stdio.h>
#include <string.h>

// ============================================
//         CONSTANTS & DEFINITIONS
// ============================================
#define MAX      50
#define FILENAME "bank_data.txt"

// ============================================
//         COLOUR CODES (for terminal)
// ============================================
#define RED     "\033[1;31m"
#define YELLOW  "\033[1;33m"
#define GREEN   "\033[1;32m"
#define RESET   "\033[0m"

// ============================================
//         DATA STRUCTURE
// ============================================
typedef struct {
    int   id;           /* Unique account ID, starts at 1001 */
    char  name[50];     /* Account holder full name           */
    float balance;      /* Current balance in DZD             */
    int   pin;          /* 4-digit PIN                        */
    int   active;       /* 1 = open, 0 = closed               */
} Account;

// ============================================
//         GLOBAL VARIABLES
// ============================================
Account accounts[MAX];
int     count  = 0;     /* Number of accounts currently stored */
int     nextID = 1001;  /* Next ID to assign                   */

// ============================================
//         FUNCTION DECLARATIONS
// ============================================
void loadData();
void saveData();
void createAccount();
int  findAccount(int id);
int  verifyPIN(int idx);
void deposit(int idx, float amount);
void withdraw(int idx, float amount);
void transfer(int from, int to, float amount);
void closeAccount(int idx);
void printStatement(int idx);
void listAllAccounts();
void bankSummary();

// ============================================
//         MAIN FUNCTION (Menu Loop)
// ============================================
int main() {

    loadData();  /* Load existing accounts from file */

    int choice;

    do {
        // Display menu
        printf("\n");
        printf(GREEN "============================================\n" RESET);
        printf(GREEN "      NATIONAL BANK OF ALGERIA -- MENU     \n" RESET);
        printf(GREEN "============================================\n" RESET);
        printf("  1. Create new account\n");
        printf("  2. Deposit funds\n");
        printf("  3. Withdraw funds\n");
        printf("  4. Transfer between accounts\n");
        printf("  5. View account statement\n");
        printf("  6. List all accounts (sorted by balance)\n");
        printf("  7. Bank summary\n");
        printf("  8. Close account\n");
        printf("  0. Save and exit\n");
        printf(GREEN "============================================\n" RESET);
        printf("  Enter your choice: ");
        scanf("%d", &choice);

        // Variables used inside switch
        int id, idx;
        float amount;
        int id2, idx2;

        switch (choice) {

            case 1:
                createAccount();
                break;

            case 2:
                printf("  Enter account ID: ");
                scanf("%d", &id);
                idx = findAccount(id);
                if (idx == -1) {
                    printf(RED "  Account not found!\n" RESET);
                    break;
                }
                if (!verifyPIN(idx)) break;
                printf("  Enter amount to deposit: ");
                scanf("%f", &amount);
                deposit(idx, amount);
                break;

            case 3:
                printf("  Enter account ID: ");
                scanf("%d", &id);
                idx = findAccount(id);
                if (idx == -1) {
                    printf(RED "  Account not found!\n" RESET);
                    break;
                }
                if (!verifyPIN(idx)) break;
                printf("  Enter amount to withdraw: ");
                scanf("%f", &amount);
                withdraw(idx, amount);
                break;

            case 4:
                printf("  Enter source account ID: ");
                scanf("%d", &id);
                idx = findAccount(id);
                if (idx == -1) {
                    printf(RED "  Source account not found!\n" RESET);
                    break;
                }
                if (!verifyPIN(idx)) break;
                printf("  Enter destination account ID: ");
                scanf("%d", &id2);
                idx2 = findAccount(id2);
                if (idx2 == -1) {
                    printf(RED "  Destination account not found!\n" RESET);
                    break;
                }
                printf("  Enter amount to transfer: ");
                scanf("%f", &amount);
                transfer(idx, idx2, amount);
                break;

            case 5:
                printf("  Enter account ID: ");
                scanf("%d", &id);
                idx = findAccount(id);
                if (idx == -1) {
                    printf(RED "  Account not found!\n" RESET);
                    break;
                }
                if (!verifyPIN(idx)) break;
                printStatement(idx);
                break;

            case 6:
                listAllAccounts();
                break;

            case 7:
                bankSummary();
                break;

            case 8:
                printf("  Enter account ID to close: ");
                scanf("%d", &id);
                idx = findAccount(id);
                if (idx == -1) {
                    printf(RED "  Account not found!\n" RESET);
                    break;
                }
                if (!verifyPIN(idx)) break;
                closeAccount(idx);
                break;

            case 0:
                saveData();
                printf(GREEN "  Data saved. Goodbye!\n" RESET);
                break;

            default:
                printf(RED "  Invalid choice! Try again.\n" RESET);
        }

    } while (choice != 0);

    return 0;
}

// ============================================
//     PLACEHOLDER FUNCTIONS (next stages)
// ============================================

void loadData()        { /* Stage 2 */ }
void saveData()        { /* Stage 2 */ }
void createAccount()   { /* Stage 3 */ }

int findAccount(int id) {
    /* Stage 3 */
    return -1;
}

int verifyPIN(int idx) {
    /* Stage 3 */
    return 1;
}

void deposit(int idx, float amount)              { /* Stage 4 */ }
void withdraw(int idx, float amount)             { /* Stage 4 */ }
void transfer(int from, int to, float amount)    { /* Stage 4 */ }
void closeAccount(int idx)                       { /* Stage 4 */ }
void printStatement(int idx)                     { /* Stage 5 */ }
void listAllAccounts()                           { /* Stage 5 */ }
void bankSummary()                               { /* Stage 5 */ }
