#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <numeric>

// Domain entities
struct Subject
{
    int id;
    std::string name;
};

struct Grade
{
    int id;
    int subjectId;
    std::string studentName;
    double score;
};

int main()
{
    // Initial catalog
    std::vector<Subject> subjects{{1, "Mathematics"}, {2, "History"}, {3, "Programming"}};
    std::vector<Grade> grades{};

    char answerReset{};
    bool keepRunning{true};

    // Data collection loop
    while (keepRunning)
    {
        int optionNumber{};
        bool isvalid{false};
        Grade newGrade{};

        do
        {
            std::cout << "\t\tSelect subject\n";
            std::cout << std::string(45, '-') << "\n";

            for (const auto &item : subjects)
            {
                std::cout << "[" << item.id << "]" << item.name << " ";
            }

            std::cout << "\n\nChoice: ";
            std::cin >> optionNumber;

            // Validate if selected ID exists in subjects
            for (const auto &item : subjects)
            {
                if (item.id == optionNumber)
                {
                    isvalid = true;
                    break;
                }
            }

            if (!isvalid)
                std::cout << "Invalid ID, Please try again...\n\n";

        } while (!isvalid);

        newGrade.subjectId = optionNumber;
        newGrade.id = grades.size() + 1;

        std::cout << "Enter full student's name: ";
        std::getline(std::cin >> std::ws, newGrade.studentName);

        std::cout << "Enter score of the student: ";
        std::cin >> newGrade.score;

        grades.push_back(newGrade);

        std::cout << "\nAdd another score? (y/n): ";
        std::cin >> answerReset;
        if (answerReset == 'n' || answerReset == 'N')
            keepRunning = false;
    }

    // --- REPORT GENERATION ---
    std::cout << '\n'
              << std::left << std::setw(5) << "ID"
              << std::setw(25) << "Student"
              << std::setw(15) << "Subject" << "Score\n";
    std::cout << std::string(55, '=') << '\n';

    for (const auto &grade : grades)
    {
        // Relational lookup using find_if
        auto it = std::find_if(subjects.begin(), subjects.end(), [grade](const Subject &s)
                               { return s.id == grade.subjectId; });

        if (it != subjects.end())
        {
            std::cout << std::left << std::setw(5) << grade.id
                      << std::setw(25) << grade.studentName
                      << std::setw(15) << it->name
                      << std::fixed << std::setprecision(1) << grade.score << '\n';
        }
    }

    // --- FINAL STATISTICS ---
    double totalSum = std::accumulate(grades.begin(), grades.end(), 0.0,
                                      [](double currentTotal, const Grade &g)
                                      { return currentTotal + g.score; });

    // Prevent division by zero
    double average{(grades.empty()) ? 0.0 : (totalSum / grades.size())};

    std::cout << std::string(55, '=') << '\n';
    std::cout << "OVERALL AVERAGE: " << std::fixed << std::setprecision(2) << average << "\n";

    return 0;
}