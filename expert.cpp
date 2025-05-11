#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// Define a simple struct to hold disease-related data
struct DiseaseInfo {
    map<string, int> symptoms;  // Symptom and their weight
    string description;
    string treatment;
};

class MedicalExpertSystem {
private:
    map<string, DiseaseInfo> knowledgeBase;

public:
    MedicalExpertSystem() {
        // Adding diseases and their data
        DiseaseInfo flu;
        flu.symptoms = { {"fever", 2}, {"cough", 2}, {"sore throat", 1} };
        flu.description = "A common viral infection causing fever, cough, and sore throat.";
        flu.treatment = "Rest, fluids, antiviral medications";
        knowledgeBase["Flu"] = flu;

        DiseaseInfo diabetes;
        diabetes.symptoms = { {"fatigue", 2}, {"frequent urination", 3}, {"blurred vision", 1} };
        diabetes.description = "A chronic condition that affects how the body processes blood sugar.";
        diabetes.treatment = "Insulin therapy, dietary changes, exercise";
        knowledgeBase["Diabetes"] = diabetes;

        DiseaseInfo hypertension;
        hypertension.symptoms = { {"headache", 1}, {"dizziness", 2}, {"chest pain", 3} };
        hypertension.description = "High blood pressure often with no symptoms.";
        hypertension.treatment = "Lifestyle changes, antihypertensive medication";
        knowledgeBase["Hypertension"] = hypertension;

        DiseaseInfo migraine;
        migraine.symptoms = { {"headache", 3}, {"nausea", 2}, {"sensitivity to light", 2} };
        migraine.description = "A neurological condition causing intense headaches, nausea, and light sensitivity.";
        migraine.treatment = "Pain relievers, rest, avoiding triggers";
        knowledgeBase["Migraine"] = migraine;

        DiseaseInfo covid;
        covid.symptoms = { {"fever", 2}, {"dry cough", 2}, {"loss of taste", 2}, {"shortness of breath", 3} };
        covid.description = "A contagious respiratory illness caused by the coronavirus.";
        covid.treatment = "Isolation, supportive care, antiviral or monoclonal antibodies if severe";
        knowledgeBase["COVID-19"] = covid;
    }

    void diagnose(const vector<string>& userSymptoms) {
        string likelyDisease = "";
        int highestScore = 0;
        string description = "", treatment = "";

        for (auto& entry : knowledgeBase) {
            string diseaseName = entry.first;
            DiseaseInfo& info = entry.second;

            int score = 0;
            for (const string& symptom : userSymptoms) {
                if (info.symptoms.find(symptom) != info.symptoms.end()) {
                    score += info.symptoms[symptom];
                }
            }

            if (score > highestScore) {
                highestScore = score;
                likelyDisease = diseaseName;
                description = info.description;
                treatment = info.treatment;
            }
        }

        if (!likelyDisease.empty()) {
            cout << "\nLikely Disease: " << likelyDisease << endl;
            cout << "Description: " << description << endl;
            cout << "Recommended Treatment: " << treatment << endl;
        } else {
            cout << "\nNo matching disease found based on the given symptoms." << endl;
        }
    }
};

int main() {
    MedicalExpertSystem system;
    vector<string> userSymptoms;
    string symptom;

    cout << "Enter symptoms one by one (type 'done' to finish):\n";
    while (true) {
        cout << "Symptom: ";
        getline(cin, symptom);
        if (symptom == "done") break;
        userSymptoms.push_back(symptom);
    }

    system.diagnose(userSymptoms);

    return 0;
}
