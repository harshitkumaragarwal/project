#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"

#define TOTAL_QUESTIONS 15

struct Question {
    char question[200];
    char options[4][100];
    int correct; // index of correct option (1–4)
};

// ✅ Function declaration
void startQuiz(struct Question q[], int total, char topic[], char name[]);

int main() {
    // --- Science Quiz Questions ---
    struct Question science[TOTAL_QUESTIONS] = {
        {"What is the SI unit of Force?", {"Joule","Newton","Pascal","Watt"}, 2},
        {"Speed of light is approximately?", {"3x10^8 m/s","3x10^6 m/s","3x10^5 km/s","3x10^3 m/s"}, 1},
        {"Which of the following is a vector quantity?", {"Speed","Mass","Velocity","Time"}, 3},
        {"The unit of electric current is?", {"Volt","Coulomb","Ohm","Ampere"}, 4},
        {"Who gave the laws of motion?", {"Einstein","Galileo","Newton","Bohr"}, 3},
        {"Chemical symbol of Sodium is?", {"So","S","Na","N"}, 3},
        {"pH value less than 7 indicates?", {"Acidic","Basic","Neutral","Alkaline"}, 1},
        {"Which gas is used in fire extinguishers?", {"Oxygen","Carbon dioxide","Nitrogen","Helium"}, 2},
        {"H2O is the chemical formula of?", {"Hydrogen peroxide","Water","Oxygen","Hydroxide"}, 2},
        {"Atomic number of Carbon is?", {"6","8","12","10"}, 1},
        {"Which planet is known as the Red Planet?", {"Venus","Earth","Mars","Jupiter"}, 3},
        {"What is the chemical symbol of Gold?", {"Ag","Au","Go","Gd"}, 2},
        {"Which law states that energy cannot be created or destroyed?", {"Ohm’s Law","Law of Conservation of Energy","Newton’s Third Law","Boyle’s Law"}, 2},
        {"Which of these is not a state of matter?", {"Solid","Liquid","Gas","Energy"}, 4},
        {"Which particle has a negative charge?", {"Proton","Electron","Neutron","Nucleus"}, 2}
    };

    // --- Physics (Laser) Quiz Questions ---
    struct Question physics[TOTAL_QUESTIONS] = {
        {"What does LASER stand for?", {"Light Amplification by Stimulated Emission of Radiation","Light Application by Stimulated Energy of Rays","Luminous Amplification by Systematic Emission of Radiation","None of these"}, 1},
        {"What type of light is produced by a laser?", {"Monochromatic and coherent","Polychromatic and incoherent","Diffuse","Irregular"}, 1},
        {"Which of these is used as a laser medium?", {"Ruby","Salt","Water","Air"}, 1},
        {"Which component reflects light back and forth in a laser?", {"Lens","Mirror","Prism","Crystal"}, 2},
        {"The first laser was built using?", {"Helium-Neon gas","Ruby crystal","Carbon dioxide gas","Diode"}, 2},
        {"Laser light is known for its?", {"High divergence","High coherence","Low intensity","Low frequency"}, 2},
        {"Which of the following is a laser application?", {"CD player","Cutting metal","Eye surgery","All of these"}, 4},
        {"The population inversion in a laser means?", {"More atoms in higher energy state","More atoms in ground state","Equal atoms in both states","None"}, 1},
        {"Which type of laser is used in barcode scanners?", {"He-Ne laser","CO2 laser","Ruby laser","Diode laser"}, 1},
        {"Which laser operates in infrared?", {"CO2 laser","He-Ne laser","Nitrogen laser","Dye laser"}, 1},
        {"Which emission process produces laser light?", {"Spontaneous emission","Stimulated emission","Photoelectric emission","Thermal emission"}, 2},
        {"Who built the first laser?", {"Einstein","Maiman","Newton","Bohr"}, 2},
        {"What color light does a ruby laser emit?", {"Green","Red","Blue","Yellow"}, 2},
        {"Which material is used in optical fiber communication?", {"Semiconductor laser","Ruby laser","CO2 laser","He-Ne laser"}, 1},
        {"Which of these is NOT an application of laser?", {"Surgery","Communication","Cooking food","Cutting metals"}, 3}
    };

    // --- User Interaction ---
    char name[50];
    int choice;

    printf("\n=====================================\n");
    printf("   🌟 WELCOME TO BRAINERGY QUIZ 🌟\n");
    printf("=====================================\n");
    printf("\nEnter your name: ");
    scanf("%s", name);

    printf("\nHello, %s! Choose your quiz topic:\n", name);
    printf("1. Science Quiz\n");
    printf("2. Physics (Laser) Quiz\n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    if (choice == 1)
        startQuiz(science, TOTAL_QUESTIONS, "Science", name);
    else if (choice == 2)
        startQuiz(physics, TOTAL_QUESTIONS, "Physics", name);
    else
        printf(RED "\nInvalid choice. Please restart the program.\n" RESET);

    return 0;
}

// ✅ Quiz Function Definition
void startQuiz(struct Question q[], int total, char topic[], char name[]) {
    int score = 0, answer;
    time_t start, end;
    double time_taken;

    printf(YELLOW "\nStarting %s Quiz for %s...\n" RESET, topic, name);
    printf("You have 2 minutes to complete the quiz!\n");
    printf("-------------------------------------------\n");

    start = time(NULL);
    srand(time(NULL));

    int order[total];
    for (int i = 0; i < total; i++) order[i] = i;
    for (int i = 0; i < total; i++) {
        int j = rand() % total;
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }

    for (int i = 0; i < total; i++) {
        end = time(NULL);
        time_taken = difftime(end, start);
        if (time_taken > 120) {
            printf(RED "\n⏰ Time’s up! Auto-submitting your quiz...\n" RESET);
            break;
        }

        printf(BLUE "\nQ%d: %s\n" RESET, i + 1, q[order[i]].question);
        for (int opt = 0; opt < 4; opt++)
            printf("%d) %s\n", opt + 1, q[order[i]].options[opt]);

        printf("Answer: ");
        scanf("%d", &answer);

        if (answer == q[order[i]].correct) {
            printf(GREEN "✅ Correct!\n" RESET);
            score++;
        } else {
            printf(RED "❌ Wrong! Correct answer: %s\n" RESET, q[order[i]].options[q[order[i]].correct - 1]);
        }
    }

    end = time(NULL);
    time_taken = difftime(end, start);

    printf("\n=====================================\n");
    printf("              RESULT\n");
    printf("=====================================\n");
    printf("Player: %s\n", name);
    printf("Topic: %s\n", topic);
    printf("Time Taken: %.0f seconds\n", time_taken);
    printf("Score: %d / %d\n", score, total);

    if (score >= 12)
        printf(GREEN "🌟 Excellent work, %s!\n" RESET, name);
    else if (score >= 8)
        printf(YELLOW "👍 Good job, keep learning!\n" RESET);
    else if (score >= 5)
        printf(YELLOW "🙂 Average performance.\n" RESET);
    else
        printf(RED "😅 Needs improvement.\n" RESET);

    FILE *f = fopen("scores.txt", "a");
    if (f) {
        fprintf(f, "Name: %s | Topic: %s | Score: %d/%d | Time: %.0f sec | Date: %s",
                name, topic, score, total, time_taken, ctime(&end));
        fclose(f);
    }
    printf(GREEN "\nYour result has been saved in 'scores.txt'.\n" RESET);
}
