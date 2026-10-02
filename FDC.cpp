#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

// FUNCTION PROTOTYPES

void displayHeader();
void displayMenu();
int getValidChoice(int min, int max);
string getActivity();
string getArchType();
string getBudget();
string recommendShoe(string activity, string arch, string budget);
void displayRecommendation(string activity, string arch, string budget, string shoe);
char getContinueChoice();
void displayFooter();
void clearInputBuffer();

// ============================================================
// MAIN FUNCTION
// ============================================================
int main() {
    char continueChoice;

    displayHeader();

    do {

        string activity = getActivity();

        string arch = getArchType();

        string budget = getBudget();

        string shoe = recommendShoe(activity, arch, budget);

        displayRecommendation(activity, arch, budget, shoe);

        continueChoice = getContinueChoice();

    } while (continueChoice == 'Y' || continueChoice == 'y');

    displayFooter();

    return 0;
}

// ============================================================
// DISPLAY HEADER
// ============================================================
void displayHeader() {
    cout << "\n";
    cout << "================================================\n";
    cout << "     👟  SHOE RECOMMENDATION SYSTEM  👟\n";
    cout << "================================================\n";
    cout << "  Find your perfect pair based on your needs!\n";
    cout << "================================================\n";
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ============================================================
// GET VALID CHOICE (input validation)
// ============================================================
int getValidChoice(int min, int max) {
    int choice;
    while (true) {
        cin >> choice;
        if (cin.fail() || choice < min || choice > max) {
            clearInputBuffer();
            cout << "  ⚠ Invalid input. Please enter a number between "
                 << min << " and " << max << ": ";
        } else {
            clearInputBuffer();
            return choice;
        }
    }
}

string getActivity() {
    cout << "\n--- STEP 1: Select Your Activity ---\n";
    cout << "1. Running / Jogging\n";
    cout << "2. Basketball\n";
    cout << "3. Casual / Everyday Wear\n";
    cout << "4. Hiking / Trail\n";
    cout << "Enter your choice (1-4): ";

    int choice = getValidChoice(1, 4);

    switch(choice) {
        case 1: return "Running";
        case 2: return "Basketball";
        case 3: return "Casual";
        case 4: return "Hiking";
        default: return "Casual";
    }
}

// ============================================================
// GET FOOT ARCH TYPE
// ============================================================
string getArchType() {
    cout << "\n--- STEP 2: Select Your Foot Arch Type ---\n";
    cout << "1. Flat Feet (low arch)\n";
    cout << "2. Neutral Arch\n";
    cout << "3. High Arch\n";
    cout << "Enter your choice (1-3): ";

    int choice = getValidChoice(1, 3);

    switch(choice) {
        case 1: return "Flat";
        case 2: return "Neutral";
        case 3: return "High";
        default: return "Neutral";
    }
}

// ============================================================
// GET BUDGET RANGE
// ============================================================
string getBudget() {
    cout << "\n--- STEP 3: Select Your Budget Range ---\n";
    cout << "1. Budget (Below RM200)\n";
    cout << "2. Mid-Range (RM200 - RM500)\n";
    cout << "3. Premium (Above RM500)\n";
    cout << "Enter your choice (1-3): ";

    int choice = getValidChoice(1, 3);

    switch(choice) {
        case 1: return "Budget";
        case 2: return "Mid-Range";
        case 3: return "Premium";
        default: return "Mid-Range";
    }
}

// ============================================================
// CORE RECOMMENDATION LOGIC
// ============================================================
string recommendShoe(string activity, string arch, string budget) {

    // ========================================================
    // RUNNING SHOES
    // ========================================================
    if (activity == "Running") {
        if (arch == "Flat") {
            if (budget == "Budget")    return "ASICS Gel-Contend 8 (RM180) - Stability for flat feet";
            if (budget == "Mid-Range") return "Brooks Adrenaline GTS 23 (RM450) - Best stability runner";
            if (budget == "Premium")   return "ASICS Gel-Kayano 30 (RM750) - Premium stability";
        }
        else if (arch == "Neutral") {
            if (budget == "Budget")    return "Nike Revolution 7 (RM180) - Affordable neutral runner";
            if (budget == "Mid-Range") return "Brooks Ghost 15 (RM480) - Smooth neutral ride";
            if (budget == "Premium")   return "Nike Vaporfly 3 (RM1,100) - Racing performance";
        }
        else if (arch == "High") {
            if (budget == "Budget")    return "New Balance 520 (RM190) - Cushioned for high arches";
            if (budget == "Mid-Range") return "Hoka Clifton 9 (RM550) - Max cushioning";
            if (budget == "Premium")   return "Hoka Bondi 8 (RM750) - Ultimate cushioning";
        }
    }

    // ========================================================
    // BASKETBALL SHOES
    // ========================================================
    else if (activity == "Basketball") {
        if (arch == "Flat") {
            if (budget == "Budget")    return "Nike Precision 7 (RM250) - Supportive budget baller";
            if (budget == "Mid-Range") return "Adidas Harden Vol. 8 (RM550) - Stability for flat feet";
            if (budget == "Premium")   return "Nike LeBron 21 (RM850) - Max support & stability";
        }
        else if (arch == "Neutral") {
            if (budget == "Budget")    return "Under Armour Lockdown 7 (RM220) - All-around performer";
            if (budget == "Mid-Range") return "Nike Kyrie 8 (RM550) - Agile court feel";
            if (budget == "Premium")   return "Nike KD 17 (RM800) - Versatile scorer's shoe";
        }
        else if (arch == "High") {
            if (budget == "Budget")    return "Adidas OwnTheGame 2.0 (RM230) - Cushioned budget";
            if (budget == "Mid-Range") return "Puma MB.03 (RM550) - Responsive cushioning";
            if (budget == "Premium")   return "Nike GT Jump 2 (RM900) - Max impact protection";
        }
    }

    else if (activity == "Casual") {
        if (budget == "Budget")    return "Adidas Runfalcon 3.0 (RM180) - Everyday comfort";
        if (budget == "Mid-Range") return "Nike Air Force 1 (RM450) - Iconic street style";
        if (budget == "Premium")   return "New Balance 990v6 (RM1,100) - Premium dad shoe";
    }

    // ========================================================
    // HIKING SHOES
    // ========================================================
    else if (activity == "Hiking") {
        if (arch == "Flat") {
            if (budget == "Budget")    return "Merrell Moab 3 (RM350) - Supportive trail shoe";
            if (budget == "Mid-Range") return "Salomon X Ultra 4 GTX (RM650) - Stability on trails";
            if (budget == "Premium")   return "Hoka Anacapa 2 GTX (RM950) - Premium hiking";
        }
        else {  // Neutral or High arch
            if (budget == "Budget")    return "Columbia Redmond III (RM300) - Affordable hiker";
            if (budget == "Mid-Range") return "Merrell Moab 3 GTX (RM550) - Waterproof classic";
            if (budget == "Premium")   return "Salomon Quest 4 GTX (RM1,000) - Expedition ready";
        }
    }

    // Fallback (should never reach here due to validation)
    return "Please consult a shoe specialist for personalized advice.";
}

// ============================================================
// DISPLAY FINAL RECOMMENDATION
// ============================================================
void displayRecommendation(string activity, string arch, string budget, string shoe) {
    cout << "\n";
    cout << "================================================\n";
    cout << "           👟 YOUR SHOE RECOMMENDATION 👟\n";
    cout << "================================================\n";
    cout << "  Activity   : " << activity << endl;
    cout << "  Arch Type  : " << arch << endl;
    cout << "  Budget     : " << budget << endl;
    cout << "------------------------------------------------\n";
    cout << "  RECOMMENDED SHOE:\n";
    cout << "  >> " << shoe << endl;
    cout << "================================================\n";
}

// ============================================================
// ASK TO CONTINUE
// ============================================================
char getContinueChoice() {
    char choice;
    cout << "\nWould you like another recommendation? (Y/N): ";
    cin >> choice;
    clearInputBuffer();
    return choice;
}

void displayFooter() {
    cout << "\n";
    cout << "================================================\n";
    cout << "  Thank you for using Shoe Recommender!\n";
    cout << "  Stay comfortable, stay active! 👟\n";
    cout << "================================================\n";
    cout << "\n";
}
