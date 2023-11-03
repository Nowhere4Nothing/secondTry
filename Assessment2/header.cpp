//
// Created by Will on 15/09/2023.
//
#include "header.h"
#include <iostream>
#include <string>
#include <random>
#include <cmath>

using namespace std;

static int numParty = 0;
static int numLeader = 0;
static int numIssue = 0;
static int numE = 0;
static int numTeam = 0;
static int numCan;
// the global variables that count the amount of objects for the arrays

static const int MAXLeader = 3;
static const int MAXCandidates = 30;
static const int MAXIssue = 5;
static const int MAXParties = 3;
static const int MAXTeam = 3;
static const int MAXElectorates = 11;
// the max amount of objects in an array. I use an array because I know beforehand the max amount that should be there

Issues *IList[MAXIssue];
Candidate *cList[MAXCandidates];
Leader *lList[MAXLeader];
CampaignManagementTeam *CMList[MAXTeam];
PoliticalParty *pList[MAXParties];
ElectoralDivision *eList[MAXElectorates];
// the array of pointers I will use to display the objects information in the program, im using this because it did not
// call my de-constructor
static random_device rd;

void Election::generateIssues() {
    random_device rdIssue;
    default_random_engine randomEngineIssue(rdIssue());
    uniform_int_distribution<int> distributionIssue(0, 19);
    bool usedIndexIssue[20] = {false};
    // a local random maker I am using to get the random index to the following array

// the global scale / random I will use for political stances and other variables that I want to be universal across the program

    string issuesArray[] = {
            "A hot dog is a sandwich", "There is no point in eating french fries without ketchup",
            "Pineapple belongs on pizza", "Fruit counts as dessert",
            "Ice cream is better than cake", "Chocolate chip cookies are the best kind of cookies",
            "You should put cereal in the bowl first, followed by milk",
            "Leftover pizza is better eaten cold, rather than reheating it",
            "You should never wear socks with sandals", "Monday is the worst day of the week.",
            " The person in the middle seat of an airline row automatically gets both armrests.",
            "Its better to be too hot than too cold.",
            " Santa Claus' elves should be paid minimum wage.", "The egg came before the chicken",
            "Darth Vader was ultimately a hero, not a villain",
            "Superheroes should have to pay for all the damage they cause.",
            "Skirts are more comfortable than pants.", "Heavy Metal is the best genre of music",
            "GIF should be pronounced with a hard G, not a soft G",
            "Traveling back in time would be better than traveling forward in time."
    }; // end array
    /*
        Instead of coming up with 5 issues I have decided to come up with mny more fun ones and put it in a massive array.
        I am doing this because it is more fun and I want to build a program where everytime I run it the winner will be different
     */

    for (int i = 0; i < MAXIssue; i++) {
        int selectIndexIssue;
        int selectIndexApp;

        do {
            selectIndexIssue = distributionIssue(randomEngineIssue);
        } // end do loop
        while (usedIndexIssue[selectIndexIssue]);

        usedIndexIssue[selectIndexIssue] = true;
        // this while loop is used so that it will not grab the same index twice. I do not want two of the same issues

        try {
            if (numIssue < MAXIssue) {
                auto issues = new Issues(issuesArray[selectIndexIssue]);

                IList[numIssue] = issues;
                numIssue++;
                // making the Issues object and sending it to the array
            } // end if
        } // end try
        catch (const bad_alloc &e) {
            cerr << "Error: failed to allocate memory for an Issue Object!" << endl;
            break;
            // using a try catch to catch a bad allocation error
        } // end catch
    } // end for
} // end method

void Issues::displayIssues() {
    cout << "Issue Name: " << issueName << endl;
}

string Issues::getIssueName() {
    return issueName;
}
// end generation of issues

void Election::generatePoliticalParties() {
    random_device rdParty;
    default_random_engine randomEngine(rdParty());

    uniform_int_distribution<int> distribution(0, 10);

    bool usedIndex[10] = {false};
    int scale[10] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
// the global scale / random I will use for political stances and other variables that I want to be universal across the program

    string politicsName[] = {
            "Labor", "Liberal",
            "Greens", "OneNation",
            "Independent", "Clive Palmer",
            "Legalise Weed", "Katter's Cybertron Party",
            "Free trade party", "Democrats",
            "Cybertron First Party"
    }; // end array
    // I used real Australian political parties as I could not be bothered to think up names

    string politicalSlogan[] = {
            "A Greener Cybertron Starts Today.", "Putting the people of Cybertron first, Always.",
            "Fiscal Responsibility and Economic Growth", "Building a Safer, Stronger Nation.",
            "The earth is flat, believe me i have seen it", "Is That True, or Did You Hear It On Fox News",
            "Lets Move Cybertron forward", "Don't just hope for a better life. Vote for it.",
            "Due To Recent Budget Cuts, The Light At The End Of The Tunnel Has Been Turned Off",
            "Your voice, our choice, always", "Evolution Is Just A Theory.. Kind Of Like Gravity"
    }; // end array
    // I used some slogans off the internet, some typical sayings and some funny satire ones

    int pFunding[] = {
            100000, 200000,
            300000, 400000,
            500000, 600000,
            700000, 800000,
            900000, 1000000,
            1100000
    }; // end array
    // The options that have the possibility of being picked for the object political party

    for (int i = 0; i < MAXParties; ++i) {
        int pPoints = 0;
        int selectedIndex, partyStance, partyLeaning, pSig, pApp;

        do {
            selectedIndex = distribution(randomEngine);
        } // end do loop
        while (usedIndex[selectedIndex]);

        usedIndex[selectedIndex] = true;
        // this while loop is used so that it will not grab the same index twice. I do not want two of the same issues

        partyStance = distribution(randomEngine) % 10;
        partyLeaning = distribution(randomEngine) % 10;
        // using a global array to get the party stance, and leaning

        try {
            if (numParty < MAXParties) {

                auto party = new PoliticalParty(i + 1, politicsName[selectedIndex], partyStance, partyLeaning,
                                                politicalSlogan[selectedIndex], pFunding[selectedIndex], pPoints);
                pList[numParty] = party;
                numParty++;
                // making the political party object and adding it to the array

                for (auto &j: IList) {
                    pSig = distribution(randomEngine) % 10;
                    pApp = distribution(randomEngine) % 10;
                    string issueName = j->getIssueName();
                    int significance = pSig;
                    int approach = pApp;

                    party->setStanceOnIssue(issueName, significance, approach);
                    // associating the issue with the political party. The arrayList that we are using is in the file header.h in the object political party
                } // end for
            } // end if
        } // end try
        catch (const bad_alloc &e) {
            cerr << "Error: failed to allocate memory for a party Object!" << endl;
            break;
            // using a try catch to catch a bad allocation error
        } // end catch
    } // end for


} // end method

void PoliticalParty::displayPoliticalParty() {
    cout << "Party ID: " << partyID << endl;
    cout << "Party Name: " << partyName << endl;
    cout << "Party slogan: " << politicalSlogan << endl;
    cout << "Political Stance score: " << politicalStance << endl;
    cout << "Political Leaning (low score is Right wing, high is left wing): " << politicalLeaning << endl;
    cout << "Party funding: " << funding << endl;
    cout << "Party Points: " << pPoints << endl << endl;
}

void PoliticalParty::displayStancesOnIssues() const {
    int count = 0;
    for (auto &stance: stancesOnIssues) {
        count++;
        // using a count, you can keep track of the issues
        if (stance.second.first != 0 || stance.second.second != 0) {
            // only runs if there is a number in the vector pair
            cout << count << ". Issue: " << stance.first << endl;
            // the issue name
            cout << "Significance: " << stance.second.first << endl;
            cout << "Political stance: " << politicalStance << endl;
            cout << "Approach: " << stance.second.second << endl << endl;
            // displaying the ints in the vector in header.h
        } else {
            cout << "Party: " << partyName << " has no stance on " << stance.first << endl;
            // only displays if there is an error
        } // end else
    } // end for
} // end method

void PoliticalParty::setStanceOnIssue(const string &issueName, int significance, int approach) {
    stancesOnIssues.emplace_back(issueName, make_pair(significance, approach));
    // putting the stances in the vector
}

pair<int, int> PoliticalParty::getStanceOnIssue(const string &issueName) const {
    for (const auto &stance: stancesOnIssues) {
        // running through the vector inn the political party
        if (stance.first == issueName) {
            return stance.second;
            // returning the stances paired with the political party must use variable.first || .second
        } // end if
    } // end for
    return make_pair(0, 0);
    // if error return 0 and 0
} // end pair

int PoliticalParty::getPartyID() const {
    return partyID;
}

string PoliticalParty::getPartyName() const {
    return partyName;
}

int PoliticalParty::getPoliticalStance() const {
    return politicalStance;
}

int PoliticalParty::getPoliticalLeaning() const {
    return politicalLeaning;
}

string PoliticalParty::getSlogan() const {
    return politicalSlogan;
}

int PoliticalParty::getFunding() const {
    return funding;
}

int PoliticalParty::getPartyPoints() const {
    return pPoints;
}

void PoliticalParty::setPartyPoints(int p) {
    pPoints += p;
}
// end generate political parties information

void Election::generatePoliticalLeader() {
    default_random_engine randomEngine(rd());

    uniform_int_distribution<int> distribution(0, 10);

    bool usedIndex[10] = {false};
    int scale[10] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
// the global scale / random I will use for political stances and other variables that I want to be universal across the program

    string leaderName[] = {
            "Kiki Simmer", "Alex Martin",
            "Olivia Harper", "Tom Plunkett",
            "Tom White", "Liam Anderson",
            "Ava Roberts", "Will Steele",
            "Max O'Donoghue", "Carmel-leigh Mahler",
            "Lockie Hunt"
    };
    // the potential names for the leader. I used my friends names

    for (int i = 0; i < MAXLeader; ++i) {
        int selectedIndex, leaderPopularityIndex, leaderPoliticalSkillIndex, leaderKnowledgeIndex;

        leaderPopularityIndex = distribution(randomEngine) % 10;
        leaderPoliticalSkillIndex = distribution(randomEngine) % 10;
        leaderKnowledgeIndex = distribution(randomEngine) % 10;
        // the random index using the global scale to get the variables for leader

        do {
            selectedIndex = distribution(randomEngine);

        } // end do loop
        while (usedIndex[selectedIndex]);

        usedIndex[selectedIndex] = true;
        // this while loop is used so that it will not grab the same index twice. I do not want two of the same issues

        try {
            if (numLeader < MAXLeader) {
                auto leader = new Leader(pList[i]->getPartyID(), pList[i]->getPartyName(),
                                         pList[i]->getPoliticalStance(), pList[i]->getPoliticalLeaning(),
                                         pList[i]->getSlogan(),
                                         pList[i]->getFunding(), pList[i]->getPartyPoints(),
                                         leaderName[selectedIndex], scale[leaderPopularityIndex],
                                         scale[leaderPoliticalSkillIndex],
                                         scale[leaderKnowledgeIndex]);
                lList[numLeader] = leader;
                numLeader++;
                // making the leader object and adding it to the array
            } // end if
        } // end try
        catch (const bad_alloc &e) {
            cerr << "Error: failed to allocate memory for a leader Object!" << endl;
            break;
            // using a try catch to catch a bad allocation error
        } // end catch
    } // end for
} // end method

void Leader::displayPoliticalLeader() {
    cout << "Party ID: " << partyID << endl;
    cout << "Party Name: " << partyName << endl;
    cout << "Party slogan: " << politicalSlogan << endl;
    cout << "Political Stance score: " << politicalStance << endl;
    cout << "Political Leaning (low score is Right wing, high is left wing): " << politicalLeaning << endl;
    cout << "Party funding: " << funding << endl;
    cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << endl;

    cout << "Leader Name: " << leaderName << endl;
    cout << "Leader Popularity: " << lPopularity << endl;
    cout << "Leader Political Skill: " << lPoliticalSkill << endl;
    cout << "Leader Knowledge: " << lKnowledge << endl << endl;
}

void Leader::setPopularity(int pp) {
    lPopularity += pp;
}

string Leader::getLeaderName() const {
    return leaderName;
}

int Leader::getLPopularity() const {
    return lPopularity;
}

int Leader::getLPoliticalSkill() const {
    return lPoliticalSkill;
}

int Leader::getLKnowledge() const {
    return lKnowledge;
}
// end generation of leader

int Election::generatePoliticalCandidate(int n) {
    default_random_engine randomEngine(rd());

    uniform_int_distribution<int> distribution(0, 10);

    bool usedIndex[10] = {false};
    int scale[10] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
// the global scale / random I will use for political stances and other variables that I want to be universal across the program

    random_device rdCan;
    default_random_engine randomEngineCan(rdCan());
    uniform_int_distribution<int> distributionCan(0, 30);
    bool usedIndexCan[31] = {false};
    // random device used for picking the candidates names

    string candidateName[31] = {
            "T'Challa", "Carol Susan Jane Danvers", "Samuel Thomas Wilson",
            "Rand K'ai", "Tony Stark", "Bruce Wayne",
            "Bruce Banner", "Miles Morales", "Clark Kent",
            "Scott Laing", "Wade Wilson", "Steve Rogers",
            "Matt Murdock", "Selina Kyle", "Barry Allen",
            "Dick Grayson", "Dianna Prince", "James Buchanan Barnes",
            "Peter Parker", "Jessica Drew", "Clinton Barton",
            "Peter Quill", "Wanda Maximoff", "Professor X",
            "Reed Richards", "Johnathon Blaze", "Oliver Jonas Queen",
            "Stephen Vincent Strange", "Jessica Jones", "Carl Lucas",
            "Natalia Alianovna Romanov",
    };
    // The options for the political candidates. I chose names from the superhero universe

    for (int i = 0; i < numParty; i++) {
        for (int j = 0; j < n; j++) {
            // using a nested for loop to make the candidates and add them to a particular political party
            // n represents the number of candidates in each political party as its the amount of electorates chosen.

            int selectedIndexCan, canPopularityIndex, canPoliticalSkillIndex, canKnowledgeIndex;
            int canPoint = 0;

            canPopularityIndex = distribution(randomEngine) % 10;
            canPoliticalSkillIndex = distribution(randomEngine) % 10;
            canKnowledgeIndex = distribution(randomEngine) % 10;
            // the random index using the global scale to get the variables for leader

            do {
                selectedIndexCan = distributionCan(randomEngineCan);
            } // end do loop
            while (usedIndexCan[selectedIndexCan]);

            usedIndexCan[selectedIndexCan] = true;
            // this while loop is used so that it will not grab the same index twice. I do not want two of the same issues

            try {
                if (numCan < MAXCandidates) {
                    auto candidate = new Candidate(pList[i]->getPartyID(), pList[i]->getPartyName(),
                                                   pList[i]->getPoliticalStance(), pList[i]->getPoliticalLeaning(),
                                                   pList[i]->getSlogan(),
                                                   pList[i]->getFunding(), pList[i]->getPartyPoints(),
                                                   j + 1, candidateName[selectedIndexCan],
                                                   scale[canPopularityIndex],
                                                   scale[canPoliticalSkillIndex], scale[canKnowledgeIndex],
                                                   canPoint);
                    cList[numCan] = candidate;
                    numCan++;
                    // making the candidate object and adding them to the array

                    for (auto &issueCan: IList) {
                        string issueName = issueCan->getIssueName();
                        int significance = pList[i]->getStanceOnIssue(issueName).first;
                        int approach = pList[i]->getStanceOnIssue(issueName).second;

                        candidate->setStanceOnIssueCan(issueName, significance, approach);
                        // associating the issue with the political party. The arrayList that we are using is in the file header.h in the object political party
                    } // end for

                } // end if
            } // end try
            catch (const bad_alloc &e) {
                cerr << "Error: failed to allocate memory for a Candidate Object!" << endl;
                break;
                // using a try catch to catch a bad allocation error
            } // end catch
        } // end for
    } // end for
    return numCan;
} // end method

string Candidate::getCanName() const {
    return canName;
}

int Candidate::getCanId() const {
    return canID;
}

int Candidate::getCanPopularity() const {
    return canPopularity;
}

int Candidate::getCanPoliticalSkill() const {
    return canPoliticalSkill;
}

int Candidate::getCanKnowledge() const {
    return canKnowledge;
}

int Candidate::getPoints() const {
    return points;
}

void Candidate::setPoints(int lp) {
    points += lp;
}

void Candidate::setPopularity(int cp) {
    canPopularity += cp;
}

void Candidate::setStanceOnIssueCan(const string &issueName, int significance, int approach) {
    for (auto &canStance: stancesOnIssuesCan) {
        if (canStance.first == issueName) {
            canStance.second = make_pair(significance, approach);
            return;
            // this is so the stances can be replaced, if this inst here it would just make a new one and not replace it
            // needed for the issues events if the candidates change their mind
        } // end if
    } // end for

    stancesOnIssuesCan.emplace_back(issueName, make_pair(significance, approach));
    // sets the stances on the issues and adds to the vector in class if there is no entry that is the same in the vector
}

pair<int, int> Candidate::getStanceOnIssueCan(const string &issueName) const {
    for (auto &stance: stancesOnIssuesCan) {
        // running through the vector in candidate
        if (stance.first == issueName) {
            return stance.second;
            // returning the stances paired with the political party.
        } // end if
    } // end for
    return make_pair(0, 0);
    // if error return 0 and 0
} // end pair
// end political candidate information generation

void Candidate::displayStancesOnIssuesCan() {
    for (auto &stance: stancesOnIssuesCan) {
        // running through the vector in Candidate
        if (stance.second.first != 0 || stance.second.second != 0) {
            // only runs if there is a number in both pairs
            cout << "Issue: " << stance.first << endl;
            cout << "Significance: " << stance.second.first << endl;
            cout << "Approach: " << stance.second.second << endl << endl;
        } else {
            cout << "Candidate: " << canName << " has no stance on " << stance.first << endl;
            // only used if there is an error
        } // end else
    } // end for
} // end method

void Candidate::displayPoliticalCandidate() {
    cout << "Candidate ID: " << canID << endl;
    cout << "Candidate Name: " << canName << endl;
    cout << "Candidate Popularity: " << canPopularity << endl;
    cout << "Candidate Political Skill: " << canPoliticalSkill << endl;
    cout << "Candidate Knowledge: " << canKnowledge << endl;
    cout << "Candidate Points: " << points << endl << endl;
}


void Election::generateCampaignTeam() {
    std::default_random_engine randomEngine(rd());

    uniform_int_distribution<int> distribution(0, 10);

    bool usedIndex[10] = {false};
    int scale[10] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
// the global scale / random I will use for political stances and other variables that I want to be universal across the program

    for (int i = 0; i < MAXTeam; ++i) {
        int teamStratSkillIndex, teamOrgSkillIndex, teamSizeIndex;

        teamStratSkillIndex = distribution(randomEngine) % 10;
        teamOrgSkillIndex = distribution(randomEngine) % 10;
        teamSizeIndex = distribution(randomEngine) % 10;
        // the random index using the global scale to get the variables for leader

        try {
            if (numTeam < MAXTeam) {
                auto team = new CampaignManagementTeam(pList[i]->getPartyID(), pList[i]->getPartyName(),
                                                       pList[i]->getPoliticalStance(),
                                                       pList[i]->getPoliticalLeaning(),
                                                       pList[i]->getSlogan(),
                                                       pList[i]->getFunding(), pList[i]->getPartyPoints(),
                                                       i + 1, scale[teamStratSkillIndex],
                                                       scale[teamOrgSkillIndex],
                                                       scale[teamSizeIndex]);
                CMList[numTeam] = team;
                numTeam++;
                // making the political team object and adding them the array
            } // end if
        } // end try
        catch (const bad_alloc &e) {
            cerr << "Error: failed to allocate memory for a leader Object!" << endl;
            break;
            // using a try catch to catch a bad allocation error
        } // end catch
    } // end for
} // end method


int CampaignManagementTeam::getTeamId() const {
    return teamID;
}

int CampaignManagementTeam::getStrategicSkill() const {
    return strategicSkill;
}

int CampaignManagementTeam::getOrganisationalSkill() const {
    return organisationalSkill;
}

int CampaignManagementTeam::getSize() const {
    return size;
}

void CampaignManagementTeam::displayTeam() {
    cout << "Political party: " << partyName << endl;
    cout << "Team ID: " << teamID << endl;
    cout << "Team strategic Skill: " << strategicSkill << endl;
    cout << "Team organisational skill: " << organisationalSkill << endl;
    cout << "Team size: " << size << endl << endl;
}
// end political Team generation information

void Election::generateElectorate(int &n) {
    default_random_engine randomEngine(rd());

    uniform_int_distribution<int> distribution(0, 10);

    bool usedIndex[10] = {false};
    int scale[10] = {
            1, 2, 3, 4, 5, 6, 7, 8, 9, 10
    };
// the global scale / random I will use for political stances and other variables that I want to be universal across the program

    random_device rdE;
    default_random_engine randomEngineE(rdE());
    uniform_int_distribution<int> distributionE(0, 19);
    bool usedIndexE[21] = {false};
    // the local random device used for picking out the electorate name

    string eName[] = {
            "Central District", "Cybertron tech Zone", "Highland Hills",
            "ChinaTown", "Soi Cowboy", "Red light District", "Riverside Heights",
            "Oceanside Heights", "Silicon Valley", "NewTown", "The Slums of Cybertron",
            "Neon Heights", "Hells Kitchen", "BackWater Barrow", "Kings View",
            "Cybertron Industrial Zone", "Red Valley", "Financial District", "Electric Hills",
            "Shinjuku"
    };
    // the option for the electorate, I combined random words that sounded cyberpunk, also used some real places

    int amountOfCit[]{
            10000, 20000,
            30000, 40000,
            50000, 60000,
            70000, 80000,
            90000, 100000,
            110000, 120000
    };
    // options for the electorate object

    for (int h = 0; h < n; h++) {
        int selectedIndexEName, selectAmount, selectedIndexELeaning, selectedIndexEStanding, eSig, eApp;

        selectedIndexELeaning = distribution(randomEngine) % 10;
        selectedIndexEStanding = distribution(randomEngine) % 10;
        selectAmount = distribution(randomEngine) % 10;
        // the random index using the global scale to get the variables for leader

        do {
            selectedIndexEName = distributionE(randomEngineE);
        } // end do loop
        while (usedIndexE[selectedIndexEName]);

        usedIndexE[selectedIndexEName] = true;
        // this while loop is used so that it will not grab the same index twice. I do not want two of the same issues

        try {
            if (n < MAXElectorates) {
                auto electorate = new ElectoralDivision(h + 1, eName[selectedIndexEName],
                                                        amountOfCit[selectAmount],
                                                        scale[selectedIndexELeaning]);
                eList[numE] = electorate;
                numE++;
                // making the electorate object and adding it to the array

                for (auto &j: IList) {
                    eSig = distribution(randomEngine) % 10;
                    eApp = distribution(randomEngine) % 10;

                    string issueName = j->getIssueName();
                    int significance = eSig;
                    int approach = eApp;

                    electorate->setStanceOnIssue(issueName, significance, approach);
                    // associating the issue with the political party.
                    // The arrayList that we are using is in the file header.h in the object political party

                } // end for
            } // end if
        } // end try
        catch (const bad_alloc &e) {
            cerr << "Error: failed to allocate memory for a Candidate Object!" << endl;
            break;
            // using a try catch to catch a bad allocation error
        } // end catch
    } // end for
} // end method

int ElectoralDivision::getElectoralId() const {
    return electoralID;
}

const string &ElectoralDivision::getElectorateName() const {
    return electorateName;
}

int ElectoralDivision::getAmountOfCitizens() const {
    return amountOfCitizens;
}

int ElectoralDivision::getELeaning() const {
    return eLeaning;
}

void ElectoralDivision::setStanceOnIssue(const string &issueName, int significance, int approach) {
    stancesOnIssues.emplace_back(issueName, make_pair(significance, approach));
    // getting the issue and placing it into the back of the vector
}

pair<int, int> ElectoralDivision::getStanceOnIssue(const string &issueName) const {
    for (const auto &stance: stancesOnIssues) {
        // running through the vector in Electoral division
        if (stance.first == issueName) {
            return stance.second;
            // returning the stances paired with the political party
        } // end if
    } // end for
    return make_pair(0, 0);
    // if error return 0 and 0
} // end pair

void ElectoralDivision::displayElecorates() const {
    cout << "Electorate ID: " << electoralID << endl;
    cout << "Electorate name: " << electorateName << endl;
    cout << "Amount of people: " << amountOfCitizens << endl;
    cout << "Electorate political leaning: (low score is Right wing, high is left wing): " << eLeaning << endl;
    cout << "--------------------" << endl;
}

void ElectoralDivision::displayStancesOnIssues() const {
    int count = 0;
    for (auto &stance: stancesOnIssues) {
        count++;
        if (stance.second.first != 0 || stance.second.second != 0) {
            // used to make sure that both stances have a number in them
            cout << count << ". Issue: " << stance.first << endl;
            // using a count to count the issue, also displaying the name of the issue
            cout << "Significance: " << stance.second.first << endl;
            // important as it is the significance that wa generated for each issue
            cout << "Approach: " << stance.second.second << endl << endl;
            // approach that was generated for each issue
        } else {
            cout << "Electorate: " << electoralID << " has no stance on " << stance.first << endl;
            // this is used if there is an error with the above code
        } // end else
    } // end for
} // end method
// end electorate generation information

void Election::displayAllGeneratedInformation(int &n, int &eNumber) {
    cout << "++++++++++++++++++++ALL GENERATED INFORMATION++++++++++++++++++++++++++" << endl << endl;

    cout << "_____________________Issues_________________________" << endl;
    for (Issues *issues: IList) {
        issues->displayIssues();
        cout << "--------------------------------" << endl << endl;
    } // end for loop
    // displaying the issues

    cout << "________________Political Party______________________" << endl;
    for (PoliticalParty *p: pList) {
        p->displayPoliticalParty();
        cout << "--------------------------------" << endl << endl;
    } // end for loop
    // displaying the political party

    cout << "_________________Political Stances__________________" << endl;
    for (int q = 0; q < numParty; q++) {
        PoliticalParty *party = pList[q];
        cout << "Party name: " << party->getPartyName() << endl;
        party->displayStancesOnIssues();
        cout << "-------------------------------" << endl << endl;

    } // end for loop
    // displaying the political stances

    cout << "______________Political Leader__________________" << endl;
    for (Leader *l: lList) {
        l->displayPoliticalLeader();
    } // end for loop
    // displaying the political leader

    cout << "______________Political Candidate________________ " << endl;
    for (int p = 0; p < numParty; p++) {
        pList[p]->displayPoliticalParty();
        for (int w = 0; w < n; w++) {
            cList[w]->displayPoliticalCandidate();
        } // end for loop
        cout << "------------------------------" << endl << endl;
        // displaying the political candidate
    }    // end for loop


    cout << "____________Political Team____________:" << endl;
    for (CampaignManagementTeam *cmt: CMList) {
        cmt->displayTeam();
    } // end for loop
    // displaying the political team


    cout << "____________Electorates_______________" << endl;
    for (int e = 0; e < eNumber; e++) {
        eList[e]->displayElecorates();
    } // end for loop
    // displaying the electorates

    cout << "__________________Electorate Stances__________________" << endl;
    for (int r = 0; r < eNumber; r++) {
        try {
            ElectoralDivision *electStance = eList[r];
            cout << "Electorate name: " << electStance->getElectorateName() << endl;
            electStance->displayStancesOnIssues();
            cout << "-------------------------------" << endl << endl;
        } catch (const bad_alloc &e) {
            cerr << "There was an error in stances on issues" << endl;
            break;
        } // end catch
    } // end for loop
    // displaying the electorate stances

// doing this here because randomly it will just throw an error for no reason

    cout << endl << "+++++++++++++++++++ALL GENERATED INFORMATION END++++++++++++++++++++++++++" << endl << endl;
}

void Election::generateCampaignEvents(int &campaignDays, int &amountOfElectorates) {
    cout << "******************************START OF CAMPAIGN**************************" << endl << endl;

    int day, division, fiftyFifty, oneInFour;
    int count = 1;
    string campaignDay;

    random_device rdEvent;
    default_random_engine randomEngineEvent(rdEvent());
    uniform_int_distribution<int> distributionFiftyFifty(0, 1);
    // random machine for the 0.5 chance to call an event
    uniform_int_distribution<int> distributionEvents(0, 3);
    // random machine for the choice of event type

    for (day = 0; day < campaignDays; day++) {
        // for loop that runs through the days of the campaign
        for (division = 0; division < amountOfElectorates; division++) {
            if (count == 1) {
                campaignDay = "Monday";
            } else if (count == 2) {
                campaignDay = "Tuesday";
            } else if (count == 3) {
                campaignDay = "Wednesday";
            } else if (count == 4) {
                campaignDay = "Thursday";
            } else if (count == 5) {
                campaignDay = "Friday";
            } else if (count == 6) {
                campaignDay = "Saturday";
            } else if (count == 7) {
                campaignDay = "Sunday";
                count = 0;
            } // looks neater not commenting after each if else

            // nested loop to take amount of campaign days with the amount of electorates
            fiftyFifty = distributionFiftyFifty(randomEngineEvent);
            oneInFour = distributionEvents(randomEngineEvent);
            // the random index to get the campaign days chance

            count++;
            cout << endl << "#####################" << campaignDay << "#######################" << endl;
            // initiating a count to count the days of the week, will use this information in candidate and leader events

            if (fiftyFifty == 0) {
                // event goes ahead
                switch (oneInFour) {
                    // one in four chance of these events going ahead
                    // using a switch case for this bit as it looks neater than an if else statement
                    case 0:
                        //general debate chosen, send off to new method
                        cout << "General Debate goes ahead for Electoral division "
                             << eList[division]->getElectoralId() << ": " << eList[division]->getElectorateName()
                             << endl;
                        generateDebate(*eList[division], campaignDay);
                        break;
                    case 1:
                        // candidate event chosen, sent off to new method
                        cout << "Candidate event goes ahead for Electoral division '"
                             << eList[division]->getElectorateName() << endl;
                        generateCandidateEvent(*eList[division], count, campaignDay);
                        break;
                    case 2:
                        // leader event chosen sent off to new method
                        cout << "Leader event goes ahead for Electoral division "
                             << eList[division]->getElectorateName()
                             << endl;
                        generateLeaderEvent(*eList[division], count, campaignDay);
                        break;
                    case 3:
                        // issue event chosen sent off to new method
                        cout << "Issue event goes ahead for Electoral division "
                             << eList[division]->getElectorateName()
                             << endl;
                        generateIssueEvent(*eList[division], count);
                        break;
                    default:
                        // error message displayed as somehow there was an issue with the generation
                        cout << "There was an error in generating Electoral events" << endl;
                        break;
                } // end switch
            } // end if statement
            else {
                // event cancelled or not put on

                cout << "There were no events for Electoral Division "
                     << eList[division]->getElectorateName() << endl;
                cout << "--------------------------------------------------" << endl << endl;
                break;
            } // end else
        } // end for
    } // end for
    cout << "******************************END OF CAMPAIGN****************************" << endl << endl;
} // end method

void Election::generateDebate(ElectoralDivision &division, string &campaignDay) {
    int maxSkillTotal = 0;
    int total;
    Candidate *winningCandidate = nullptr;
    // using a null pointer but will eventually hold the winning candidate that has the total points

    cout << "__________________START DEBATE_______________" << endl;
    cout << "The winner is the candidate that has the most total points in the following skills" << endl;

    for (int t = 0; t < numTeam; t++) {
        cout << "Political Team " << CMList[t]->getTeamId() << ": " << CMList[t]->getPartyName() << " has: "
             << endl;
        cout << "Organisational Skill: " << CMList[t]->getOrganisationalSkill() << endl;
        cout << "Team strategic Skill: " << CMList[t]->getStrategicSkill() << endl;
        cout << "Team size: " << CMList[t]->getSize() << endl;
        // displaying the values

        int teamTotalSkill =
                CMList[t]->getStrategicSkill() + CMList[t]->getOrganisationalSkill() + CMList[t]->getSize();
        cout << "Political Team " << CMList[t]->getTeamId() << " has " << teamTotalSkill << endl << endl;
        // using a loop to run over the array for teams to get the total points for each team, and displaying it

        for (int y = 0; y < numCan; y++) {
            // using a nested for loop as I have to combine all the points together for everyone, cant use two different loops
            if (division.getElectoralId() == cList[y]->getCanId()) {
                // have to make sure it only grabs the candidates associated with the electorate
                if (cList[y]->getPartyID() == CMList[t]->getPartyID()) {
                    // only getting the candidates associated with the same political team
                    cout << "Candidate Name: " << cList[y]->getCanName() << endl;
                    cout << "Candidate Popularity: " << cList[y]->getCanPopularity() << endl;
                    cout << "Candidate Political Skill: " << cList[y]->getCanPoliticalSkill() << endl;
                    cout << "Candidate Knowledge: " << cList[y]->getCanKnowledge() << endl;
                    // displaying the values

                    int candidateSkillTotal = cList[y]->getCanKnowledge() + cList[y]->getCanPoliticalSkill() +
                                              cList[y]->getCanPopularity();
                    cout << "Political candidate " << cList[y]->getCanName() << " has " << candidateSkillTotal
                         << endl;
                    // running the loop to get the variables

                    total = teamTotalSkill + candidateSkillTotal;
                    cout << "total: " << total << endl << endl;
                    // adding both totals together and displaying it

                    if (teamTotalSkill > maxSkillTotal && candidateSkillTotal > maxSkillTotal) {
                        maxSkillTotal = max(teamTotalSkill, candidateSkillTotal);
                        winningCandidate = cList[y];
                        // this if statement is getting the total and sending it off to the object outside the loop
                    } // end if
                } // end if
            } // end if
        } // end for
    } // end for

    if (winningCandidate != nullptr) {
        winningCandidate->setPopularity(10);
        // the winner gets some more points to their variables

        cout << "The Winner of the debate is " << winningCandidate->getCanName() << " with a total of " << total
             << endl;

        cout << winningCandidate->getCanName() << " gets +10 to popularity!! Their popularity is now: "
             << winningCandidate->getCanPopularity() << endl;
        cout << "The people love them! HIP HIP HOORAY!!" << endl << endl;
        // displaying the values
    } // end if
    cout << "__________________END DEBATE_______________" << endl << endl;
} // end method

void Election::generateCandidateEvent(ElectoralDivision &division, int &count, string &campaignDay) {
// do a negative and a positive event
// need to use electorate leaning, amount of people, party leaning and candidate popularity, knowledge, skill
    cout << "__________________START CANDIDATE EVENT_______________" << endl;
    cout << "There is a chance this event could be a negative or positive event!" << endl;
    cout << "This event will be based on the amount of citizens that attend the event" << endl;
    cout << "If less than 0.1 of the electorate population attend then candidate will lose popularity" << endl;
    cout << "If more than 0.1 of the electorate population attend then candidate will gain popularity" << endl
         << endl;

    random_device rdCanEvent;
    default_random_engine randomEngineEvent(rdCanEvent());

    uniform_int_distribution<int> distributionEventName(0, 10);
    uniform_int_distribution<int> distributionEventInside(0, 1);
    uniform_real_distribution<double> unifr1(0.0, 1.0);

    double amountOfCitizensAtEvent, weatherPoint;
    double leaningTotal = 0.0;
    double weatherTotal = 0.0;
    double popTotal = 0.0;
    double dayTotal = 0.0;
    double fundingTotal = 0.0;
    double leaderLiked = 0.0;
    int typeOfEvent, insideOrOut;
    string weather, inOrOut;

    weatherPoint = unifr1(randomEngineEvent);
    insideOrOut = distributionEventInside(randomEngineEvent);

    switch (insideOrOut) {
        case 0:
            inOrOut = "Outside";
            break;
        case 1:
            inOrOut = "Inside";
            break;
        default:
            cout << "There was a problem with the switch case for inside or out";
            break;
    }

    if (weatherPoint <= 0.4) {
        weather = "Sunny";
    } else if (weatherPoint > 0.5 && weatherPoint <= 0.6) {
        weather = "Raining";
    } else if (weatherPoint > 0.7 && weatherPoint <= 0.9) {
        weather = "Cloudy";
    } else {
        weather = "Snowing";
    } // end if
    // random weather pattern

    string eventName[] = {
            "sausage sizzle", "meet and greet", "political rally", "protest",
            "Town Hall Meeting", "Charity Fundraiser Gala", "Environmental Cleanup",
            "Senior Citizen Luncheons",
            "Volunteer Training Workshops", "Campaign Fundraising Gala", "Street advertising event"
    };
    // array of event ideas

    cout << "ELECTORATE INFORMATION" << endl;
    cout << "Leaning: " << division.getELeaning() << endl;
    cout << "Population: " << division.getAmountOfCitizens() << endl;
    cout << "Everyone starts with default attendance of 0 people" << endl;
    // displaying the relevant details of the electorate


    for (int l = 0; l < numCan; l++) {
        // for loop to run through the candidates
        if (division.getElectoralId() == cList[l]->getCanId()) {
            amountOfCitizensAtEvent = 0;
            // line here to reset the counter

            typeOfEvent = distributionEventName(rdCanEvent);
            cout << endl << "NAME OF EVENT: " << eventName[typeOfEvent] << endl;
            cout << "Candidate Name: " << cList[l]->getCanName() << endl;

            for (int g = 0; g < numParty; g++) {
                if (cList[l]->getPartyID() == lList[g]->getPartyID()) {
                    cout << "Candidate leaders name: " << lList[g]->getLeaderName() << endl;
                    /*
                     * This was a real pain as there are always more candidates than parties unless there is only one electorate
                     * this is designed to run through and display th parties when there is more than three. Avoiding bad_alloc
                     */
                } // end if
            } // end for

            cout << "Candidate Leaning: " << cList[l]->getPoliticalLeaning() << endl;
            cout << "Candidate: popularity: " << cList[l]->getCanPopularity() << endl;
            cout << "Candidate funding: " << cList[l]->getFunding() << endl;
            cout << "Day of the week: " << campaignDay << endl;
            cout << "WEATHER: " << weather << endl;
            cout << "Event inside or Outside: " << inOrOut << endl << endl;
            // displaying the details of the event and candidate

            if (cList[l]->getPoliticalLeaning() < 5 && division.getELeaning() < 5 ||
                cList[l]->getPoliticalLeaning() > 5 && division.getELeaning() > 5) {
                leaningTotal += division.getAmountOfCitizens() * 0.05;
                cout << "political leaning is the same gain " << leaningTotal << endl;
            } else {
                leaningTotal -= division.getAmountOfCitizens() * 0.03;
                cout << "political leaning is not the same lose " << leaningTotal << endl;
            } // end else
            // determining if the electorate is the same political leaning as the candidate
            // if yes then it is a positive attendance if not then it is a negative

            if (weather == "Sunny" && inOrOut == "Outside") {
                weatherTotal += division.getAmountOfCitizens() * 0.06;
                cout << "Day is Sunny and event outside gain " << weatherTotal << endl;
            } else if (weather == "Sunny" && inOrOut == "Inside") {
                weatherTotal += division.getAmountOfCitizens() * 0.04;
                cout << "Day is Sunny and event inside gain " << weatherTotal << endl;
            } else if (weather == "Raining" && inOrOut == "Outside") {
                weatherTotal -= division.getAmountOfCitizens() * 0.03;
                cout << "Day is Raining and event outside, lose " << weatherTotal << endl;
            } else if (weather == "Raining" && inOrOut == "Inside") {
                weatherTotal += division.getAmountOfCitizens() * 0.05;
                cout << "Day is Raining and event inside, gain " << weatherTotal << endl;
            } else if (weather == "Cloudy" && inOrOut == "Outside") {
                weatherTotal += division.getAmountOfCitizens() * 0.04;
                cout << "Day is cloudy and event outside, gain " << weatherTotal << endl;
            } else if (weather == "Cloudy" && inOrOut == "Inside") {
                weatherTotal += division.getAmountOfCitizens() * 0.04;
                cout << "Day is cloudy and event inside, gain " << weatherTotal << endl;
            } else if (weather == "Snowing" && inOrOut == "Outside") {
                weatherTotal -= division.getAmountOfCitizens() * 0.03;
                cout << "Day is snowing and event outside, lose " << weatherTotal << endl;
            } else if (weather == "Snowing" && inOrOut == "Inside") {
                weatherTotal += division.getAmountOfCitizens() * 0.05;
                cout << "Day is snowing and event inside, gain " << weatherTotal << endl;
            } // end if
            // using random weather to determine if the event will be good or bad

            if (cList[l]->getCanPopularity() >= 10) {
                popTotal += division.getAmountOfCitizens() * 0.06;
                cout << "Candidate is very popular, gain " << popTotal << endl;
            } else if (cList[l]->getCanPopularity() < 10 && cList[l]->getCanPopularity() >= 6) {
                popTotal += division.getAmountOfCitizens() * 0.02;
                cout << "Candidate is liked, gain " << popTotal << endl;
            } else if (cList[l]->getCanPopularity() < 6 && cList[l]->getCanPopularity() >= 4) {
                popTotal += division.getAmountOfCitizens() * 0.01;
                cout << "The people put up with you, gain " << popTotal << endl;
            } else {
                popTotal -= division.getAmountOfCitizens() * 0.04;
                cout << "Candidate is hated, lose " << popTotal << endl;
            } // end if
            // using the candidate popularity to determine if the attendance will be good or bad

            if (count <= 2) {
                dayTotal -= division.getAmountOfCitizens() * 0.02;
                cout << "Event is on Monday or Tues, lose " << dayTotal << endl;
            } else if (count > 2 && count <= 4) {
                dayTotal -= division.getAmountOfCitizens() * 0.01;
                cout << "Event is on Wednesday or Thursday, lose " << dayTotal << endl;
            } else if (count == 5) {
                dayTotal += division.getAmountOfCitizens() * 0.01;
                cout << "Event is on friday, gain " << dayTotal << endl;
            } else {
                dayTotal += division.getAmountOfCitizens() * 0.05;
                cout << "Event is on the weekend, gain " << dayTotal << endl;
            } // end if
            // using the days of the week to determine if the attendance will be good or bad

            for (int n = 0; n < numParty; n++) {
                // having to do another for loop inside as it broke my code otherwise the index went highter than the max index in
                // the political party array
                if (cList[l]->getPartyID() == lList[n]->getPartyID()) {
                    if (cList[l]->getFunding() >= 800000 && CMList[n]->getOrganisationalSkill() >= 8) {
                        fundingTotal += division.getAmountOfCitizens() * 0.05;
                        cout << "Event is very well funded and organised, gain" << fundingTotal;
                    } else if (cList[l]->getFunding() < 800000 && cList[l]->getFunding() >= 400000 &&
                               CMList[n]->getOrganisationalSkill() < 8 &&
                               CMList[n]->getOrganisationalSkill() >= 3) {
                        fundingTotal += division.getAmountOfCitizens() * 0.03;
                        cout << "Event is fairly funded and organised, gain" << fundingTotal << endl;
                    } else {
                        fundingTotal -= division.getAmountOfCitizens() * 0.02;
                        cout << "Event is either not well funded or not well organised, loose: " << fundingTotal
                             << endl;
                    } // end if
                    // this is comparing the funding and team organisation skills
                    // a successful event should be well funded and organised

                    if (lList[n]->getLPopularity() >= 5) {
                        leaderLiked += division.getAmountOfCitizens() * 0.03;
                        cout << "Candidate leader is liked, gain " << leaderLiked << endl;
                    } else {
                        leaderLiked -= division.getAmountOfCitizens() * 0.03;
                        cout << "Candidate leader is disliked, loose " << leaderLiked << endl;
                    } // end if
                    //this is getting the candidates leader score, the leader must be well liked
                } // end if statement
            } // end for loop

            amountOfCitizensAtEvent =
                    leaningTotal + weatherTotal + popTotal + dayTotal + fundingTotal + leaderLiked;
            // adding it all together

            if (amountOfCitizensAtEvent < 0) {
                amountOfCitizensAtEvent = 0;
            } // cant have minus amount of people at an event so if lower it will be displayed as 0

            cout << endl << "Amount attending event of " << cList[l]->getCanName() << ": "
                 << amountOfCitizensAtEvent
                 << endl;

            if (amountOfCitizensAtEvent >= division.getAmountOfCitizens() * 0.1) {
                cout << endl << "[[[[[[[[[[[[[EVENT SUCCESSFUL!!]]]]]]]]]]]]]" << endl;
                cout << "Everyone loved the events, " << cList[l]->getCanName() << " is popular!" << endl;
                cout << cList[l]->getCanName() << " gets +8 to their popularity" << endl << endl;
                cList[l]->setPopularity(8);
            } else {
                cout << endl << "[[[[[[[[EVENT FAILURE]]]]]]]]]" << endl;
                cout << cList[l]->getCanName() << " gets -3 to their popularity" << endl;
                cout << "Well that sucks, oh well you will get them next time" << endl << endl;
                cList[l]->setPopularity(-3);
                // setting the 2 different events, if it is a success they gain popularity if it is not then they loose it
            } // end if
        } // end if
    } // end for
    cout << "__________________END CANDIDATE EVENT_______________" << endl << endl;
} // end method

void Election::generateLeaderEvent(ElectoralDivision &division, int &count, string &campaignDay) {
// do a negative and positive event
    cout << "__________________START LEADER EVENT_______________" << endl;
    cout << "There is a chance this event could be a negative or positive event!" << endl;
    cout << "This event will be based on the amount of citizens that attend the event" << endl;
    cout << "If less than 0.1 of the electorate population attend then Leader will lose popularity" << endl;
    cout << "If more than 0.1 of the electorate population attend then Leader will gain popularity" << endl << endl;

    random_device rdCanEvent;
    default_random_engine randomEngineEvent(rdCanEvent());

    uniform_int_distribution<int> distributionEventName(0, 10);
    uniform_int_distribution<int> distributionEventInside(0, 1);
    uniform_real_distribution<double> unifr1(0.0, 1.0);

    double amountOfCitizensAtEvent, weatherPoint;
    double leaningTotal = 0.0;
    double weatherTotal = 0.0;
    double popTotal = 0.0;
    double dayTotal = 0.0;
    double fundingTotal;
    int typeOfEvent, insideOrOut;
    string weather, inOrOut;

    weatherPoint = unifr1(randomEngineEvent);
    insideOrOut = distributionEventInside(randomEngineEvent);

    switch (insideOrOut) {
        case 0:
            inOrOut = "Outside";
            break;
        case 1:
            inOrOut = "Inside";
            break;
        default:
            cout << "There was a problem with the switch case for inside or out";
            break;
    } // end switch statement
    // switch to get the inside or out for an event

    if (weatherPoint <= 0.4) {
        weather = "Sunny";
    } else if (weatherPoint > 0.5 && weatherPoint <= 0.6) {
        weather = "Raining";
    } else if (weatherPoint > 0.7 && weatherPoint <= 0.9) {
        weather = "Cloudy";
    } else {
        weather = "Snowing";
    } // end if
    // random weather pattern

    string eventName[] = {
            "sausage sizzle", "meet and greet", "political rally", "protest",
            "Town Hall Meeting", "Charity Fundraiser Gala", "Environmental Cleanup",
            "Senior Citizen Luncheons",
            "Volunteer Training Workshops", "Campaign Fundraising Gala", "Street advertising event"
    };
    // array of random event types

    cout << "ELECTORATE INFORMATION" << endl;
    cout << "Leaning: " << division.getELeaning() << endl;
    cout << "Population: " << division.getAmountOfCitizens() << endl;
    cout << "Everyone starts with default attendance of 0 people" << endl;
    // displaying the relevant details of the electorate

    for (int l = 0; l < numLeader; l++) {
        //makes this for loop easier as it will always be 3!
        amountOfCitizensAtEvent = 0;
        // line here to reset the counter

        typeOfEvent = distributionEventName(rdCanEvent);
        cout << endl << "NAME OF EVENT: " << eventName[typeOfEvent] << endl;
        cout << "Leader Name: " << lList[l]->getLeaderName() << endl;
        cout << "Leader Leaning: " << lList[l]->getPoliticalLeaning() << endl;
        cout << "Leader Knowledge: " << lList[l]->getLKnowledge() << endl;
        cout << "Leader Political Skill: " << lList[l]->getLPoliticalSkill() << endl;
        cout << "Leader: popularity: " << lList[l]->getLPopularity() << endl;
        cout << "Leader funding: " << lList[l]->getFunding() << endl;
        cout << "Day of the week: " << campaignDay << endl;
        cout << "WEATHER: " << weather << endl;
        cout << "Event inside or Outside: " << inOrOut << endl << endl;
        // displaying the details of the event and candidate

        if (lList[l]->getPoliticalLeaning() < 5 && division.getELeaning() < 5 ||
            lList[l]->getPoliticalLeaning() > 5 && division.getELeaning() > 5) {
            leaningTotal += division.getAmountOfCitizens() * 0.05;
            cout << "political leaning is the same gain " << leaningTotal << endl;
        } else {
            leaningTotal -= division.getAmountOfCitizens() * 0.03;
            cout << "political leaning is not the same lose " << leaningTotal << endl;
        } // end else
        // determining if the electorate is the same political leaning as the leader
        // if yes then it is a positive attendance if not then it is a negative

        if (weather == "Sunny" && inOrOut == "Outside") {
            weatherTotal += division.getAmountOfCitizens() * 0.07;
            cout << "Day is Sunny and event outside gain " << weatherTotal << endl;
        } else if (weather == "Sunny" && inOrOut == "Inside") {
            weatherTotal += division.getAmountOfCitizens() * 0.04;
            cout << "Day is Sunny and event inside gain " << weatherTotal << endl;
        } else if (weather == "Raining" && inOrOut == "Outside") {
            weatherTotal -= division.getAmountOfCitizens() * 0.03;
            cout << "Day is Raining and event outside, lose " << weatherTotal << endl;
        } else if (weather == "Raining" && inOrOut == "Inside") {
            weatherTotal += division.getAmountOfCitizens() * 0.05;
            cout << "Day is Raining and event inside, gain " << weatherTotal << endl;
        } else if (weather == "Cloudy" && inOrOut == "Outside") {
            weatherTotal += division.getAmountOfCitizens() * 0.04;
            cout << "Day is cloudy and event outside, gain " << weatherTotal << endl;
        } else if (weather == "Cloudy" && inOrOut == "Inside") {
            weatherTotal += division.getAmountOfCitizens() * 0.04;
            cout << "Day is cloudy and event inside, gain " << weatherTotal << endl;
        } else if (weather == "Snowing" && inOrOut == "Outside") {
            weatherTotal -= division.getAmountOfCitizens() * 0.03;
            cout << "Day is snowing and event outside, lose " << weatherTotal << endl;
        } else if (weather == "Snowing" && inOrOut == "Inside") {
            weatherTotal += division.getAmountOfCitizens() * 0.05;
            cout << "Day is snowing and event inside, gain " << weatherTotal << endl;
        } // end if
        // using random weather to determine if the event will be good or bad

        if (lList[l]->getLPopularity() >= 10) {
            popTotal += division.getAmountOfCitizens() * 0.06;
            cout << "Leader is very popular, gain " << popTotal << endl;
        } else if (lList[l]->getLPopularity() < 10 && lList[l]->getLPopularity() >= 6) {
            popTotal += division.getAmountOfCitizens() * 0.04;
            cout << "Leader is liked, gain " << popTotal << endl;
        } else if (lList[l]->getLPopularity() < 6 && lList[l]->getLPopularity() >= 4) {
            popTotal += division.getAmountOfCitizens() * 0.01;
            cout << "The people put up with you, gain " << popTotal << endl;
        } else {
            popTotal -= division.getAmountOfCitizens() * 0.04;
            cout << "Candidate is hated, lose " << popTotal << endl;
        } // end if
        // using the Leader popularity to determine if the attendance will be good or bad

        if (count <= 2) {
            dayTotal -= division.getAmountOfCitizens() * 0.02;
            cout << "Event is on Monday or Tues, lose " << dayTotal << endl;
        } else if (count > 2 && count <= 4) {
            dayTotal -= division.getAmountOfCitizens() * 0.01;
            cout << "Event is on Wednesday or Thursday, lose " << dayTotal << endl;
        } else if (count == 5) {
            dayTotal += division.getAmountOfCitizens() * 0.03;
            cout << "Event is on friday, gain " << dayTotal << endl;
        } else {
            dayTotal += division.getAmountOfCitizens() * 0.06;
            cout << "Event is on the weekend, gain " << dayTotal << endl;
        } // end if
        // using the days of the week to determine if the attendance will be good or bad

        if (lList[l]->getFunding() >= 800000 && CMList[l]->getOrganisationalSkill() >= 8) {
            fundingTotal += division.getAmountOfCitizens() * 0.06;
            cout << "Event is very well funded and organised, gain" << fundingTotal;
        } else if (lList[l]->getFunding() < 800000 && lList[l]->getFunding() >= 400000 &&
                   CMList[l]->getOrganisationalSkill() < 8 && CMList[l]->getOrganisationalSkill() >= 3) {
            fundingTotal += division.getAmountOfCitizens() * 0.03;
            cout << "Event is fairly funded and organised, gain" << fundingTotal << endl;
        } else {
            fundingTotal -= division.getAmountOfCitizens() * 0.02;
            cout << "Event is either not well funded or not well organised, loose: " << fundingTotal << endl;
        } // end if
        // this is comparing the funding and team organisation skills
        // a successful event should be well funded and organised

        amountOfCitizensAtEvent = leaningTotal + weatherTotal + popTotal + dayTotal + fundingTotal;
        // adding it all together

        if (amountOfCitizensAtEvent < 0) {
            amountOfCitizensAtEvent = 0;
            cout << "Citizens have been reset to 0 if less than 0";
        } // cant have minus amount of people at an event so if lower it will be displayed as 0

        cout << endl << "Amount attending event of " << cList[l]->getCanName() << ": " << amountOfCitizensAtEvent
             << endl;

        if (amountOfCitizensAtEvent >= division.getAmountOfCitizens() * 0.1) {
            cout << endl << "[[[[[[[EVENT SUCCESSFUL]]]]]]]]" << endl;
            cout << "Everyone loved the events, " << lList[l]->getLeaderName() << " is popular!" << endl;
            cout << lList[l]->getLeaderName() << " gets +8 to their popularity" << endl << endl;
            lList[l]->setPopularity(+9);
        } else {
            cout << endl << "[[[[[[[EVENT FAILURE]]]]]]]]" << endl;
            cout << lList[l]->getLeaderName() << " gets -3 to their popularity" << endl;
            cout << "Well that sucks, oh well you will get them next time" << endl << endl;
            lList[l]->setPopularity(-3);
        } // end if
        // setting the 2 different events, if it is a success they gain popularity if it is not then they loose it
    } // end for
    cout << "__________________END LEADER EVENT_______________" << endl << endl;
}

void Election::generateIssueEvent(ElectoralDivision &division, int &count) {
    cout << "__________________START ISSUE EVENT_______________" << endl;
    cout << "Picks a random issue from the array and compares stances and approach." << endl;
    cout << "If the electorate and politicians stats are too different, the politician loses popularity "
            "but a 50% chance to change stance" << endl;
    cout << "A small change in stance is changing one Sig or approach to the same as the candidates" << endl;
    cout << "A large change is completely changing the candidates opinions to that of the electorate" << endl;
    int selectedIndex, selectIndexFifty;
    random_device rdIssueEvent;
    default_random_engine randomEngineEvent(rdIssueEvent());
    uniform_int_distribution<int> distributionEventName(0, 4);
    uniform_int_distribution<int> distributionEventFiftyFifty(0, 1);

    selectedIndex = distributionEventName(randomEngineEvent);
    // the random generators needed for the following method

    Issues *issues;
    issues = IList[selectedIndex];
    issues->displayIssues();
// using a pointer get the selected issue from the array with the random index

    pair<int, int> myPairE = division.getStanceOnIssue(issues->getIssueName());
    cout << "Division " << division.getElectorateName() << ": " << endl;
    cout << "Significance: " << myPairE.first << endl;
    cout << "Approach: " << myPairE.second << endl;
    // getting the electorates stances and displaying them on the screen

    for (int l = 0; l < numCan; l++) {
        selectIndexFifty = distributionEventFiftyFifty(randomEngineEvent);
        // the fifty-fifty index, needs to be in the for loop to be generated every time or all the chances will be the same
        if (division.getElectoralId() == cList[l]->getCanId()) {
            // getting the right candidates
            pair<int, int> myPairC = cList[l]->getStanceOnIssueCan(issues->getIssueName());
            cout << "Candidate name: " << cList[l]->getCanName() << ": " << endl;
            cout << "Candidate party: " << cList[l]->getPartyName() << endl;
            cout << "Significance to Candidate: " << myPairC.first << endl;
            cout << "Approach: " << myPairC.second << endl << endl;
            // getting the candidates stances and displaying them on the screen

            double sigDistance = (pow(myPairE.first - myPairC.first, 2)) +
                                 (pow(myPairE.second - myPairC.second, 2));
            double distanceOne = sqrt(sigDistance);

            cout << "Average stance Euclidean distance is : " << distanceOne << endl << endl;
            // calculating the Average Stance Euclidean distance from the previous variables in the vector

            if (distanceOne <= 2.0) {
                cout << "[[[[[[[[[[[[[[[[[[[[[ISSUES EVENT SUCCESS]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
                cout << cList[l]->getCanName() << " has the closest stance to the electorate!!" << endl;
                cout << "Good for them, they are one with the people!!" << endl;
                cout << "They get +7 to popularity, no changes in stance!!" << endl << endl;
                cout << "can pop: " << cList[l]->getCanPopularity() << endl;
                cList[l]->setPopularity(7);
                cout << "can pop: " << cList[l]->getCanPopularity() << endl;
                cout << "_______________________________________________________________________" << endl << endl;
                // this is the first success and adds pop to the candidate
            } else if (distanceOne > 2.0 && distanceOne <= 6.0) {
                cout << "[[[[[[[[[[[[[[[[[[[[[ISSUES EVENT SUCCESS]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
                cout << cList[l]->getCanName() << " is not the closest but still in touch to the electorate!!"
                     << endl;
                cout << "Good for them, they are on the right track!!" << endl;
                cout << "They get +3 to popularity, but a 50% chance for a small change in stance!!" << endl
                     << endl;
                cout << "can pop: " << cList[l]->getCanPopularity() << endl;

                cList[l]->setPopularity(3);
                cout << "can pop: " << cList[l]->getCanPopularity() << endl;
                // second success and adds a little bit of pop to the candidate
                if (selectIndexFifty == 0) {
                    // gives chance to slightly change the stance
                    cout << "*******************VIEW CHANGE*****************" << endl;
                    cout << "The candidate changed their view slightly, yay!! They listened to the electorate!!"
                         << endl;
                    int significance = myPairE.first;
                    int approach = myPairC.second;

                    cList[l]->setStanceOnIssueCan(issues->getIssueName(), significance, approach);
                    /*
                     I put a cout << "Significance to Candidate: " << myPairC.first << endl;
                        cout << "Approach: " << myPairC.second << endl;
                      but annoyingly after debugging for a whole day and wondering y it would not change the variables in the vector
                      I put a for loop outside this one to display it and turns out it updates it, but not in this for loop!!
                      */

                    cout << "After change:" << endl;
                    cout << "significance: " << myPairC.first << endl;
                    cout << "Approach: " << myPairC.second << endl;
                    cout << "_______________________________________________________________________" << endl
                         << endl;
                } else {
                    // chance to change failure
                    cout
                            << "The candidate didnt change their view, that is a shame, they did not listen to the electorate!!"
                            << endl;
                    cout << "_______________________________________________________________________" << endl
                         << endl;
                }
            } else {
                // the final outcome, its a failure, can loses pop but has a chance to change views completely
                cout << "[[[[[[[[[[[[[[[[[[[[[ISSUES EVENT Failure]]]]]]]]]]]]]]]]]]]]]]]]]]]]" << endl;
                cout << cList[l]->getCanName() << " is not in touch with the electorate!!" << endl;
                cout << "Not good, they have not listened to their  continents!!" << endl;
                cout << "They get -5 to popularity,  but a 50% chance for large changes in stance!!" << endl
                     << endl;
                cout << "can pop: " << cList[l]->getCanPopularity() << endl;

                cList[l]->setPopularity(-5);
                cout << "can pop: " << cList[l]->getCanPopularity() << endl;

                if (selectIndexFifty == 0) {
                    //the chance to change their views
                    cout << "*******************VIEW CHANGE*****************" << endl;
                    cout << "The candidate changed their view, yay!! They listened to the electorate!!" << endl
                         << endl;

                    int significance, approach;

                    significance = myPairE.first;
                    approach = myPairE.second;

                    cList[l]->setStanceOnIssueCan(issues->getIssueName(), significance, approach);
                    // setting the new stances

                    cout << "Candidate name: " << cList[l]->getCanName() << ": " << endl;
                    cout << "Candidate party: " << cList[l]->getPartyName() << endl;
                    cout << "After change:" << endl;
                    cout << "significance: " << myPairC.first << endl;
                    cout << "Approach: " << myPairC.second << endl;

                    cout << "_______________________________________________________________________" << endl
                         << endl;
                } else {
                    // chance failed
                    cout
                            << "The candidate didnt change their view, that is a shame, they did not listen to the electorate!!"
                            << endl;
                    cout << "_______________________________________________________________________" << endl
                         << endl;
                } // end else
            } // end else
        }// end if
    } // end for
    cout << "__________________END ISSUE EVENT_______________" << endl << endl;
} //end method

void Election::decideWinner(int &m, int &n) {
    cout << "------------------------------------------START REPORT--------------------------------------" << endl
         << endl;
    cout << "______________Political Candidate________________ " << endl;
    for (int p = 0; p < numParty; p++) {
        pList[p]->displayPoliticalParty();
        for (int w = 0; w < n; w++) {
            cList[w]->displayPoliticalCandidate();
        } // end for loop
        cout << "------------------------------" << endl << endl;
        // displaying the political candidate
    }    // end for loop

    for (int e = 0; e < n; e++) {
        eList[e]->displayElecorates();
    } // end for loop
    // displaying the electorates

    for (int q = 0; q < numCan; q++) {
        try {
            Candidate *party = cList[q];
            cout << "CandidateName: " << party->getCanName() << endl;
            party->displayStancesOnIssuesCan();
            cout << "-------------------------------" << endl << endl;
        } catch (const bad_alloc &e) {
            cerr << "There was an error in stances on issues" << endl;
            break;
        } // end catch
    } // end for loop

    cout << "----------------------------------------------END REPORT-----------------------------------" << endl
         << endl;

    cout << "////////////////////////////////VOTING DAY///////////////////////////////////" << endl << endl;
    cout << "After " << m
         << " days the election is finally upon us. Who will the public vote for. We will soon find out!" << endl;
    cout
            << "First we will show a report of out political parties and candidates to see who is in the running to win"
            << endl << endl;

    int winningPoints = 0;
    cout << "We calculate the Average stance Euclidean distance for each candidate and electorate" << endl;
    for (int b = 0; b < numIssue; b++) {
        // using a for loop to rn through the issues
        cout << "Issue: " << IList[b]->getIssueName() << endl << endl;
        for (int x = 0; x < numE; x++) {
            // running through the electorates
            int winningIndex = -1;
            double winningStance = 20.0;

            pair<int, int> myPairE = eList[x]->getStanceOnIssue(IList[b]->getIssueName());
            cout << "Division " << eList[x]->getElectorateName() << ": " << endl;
            cout << "Significance: " << myPairE.first << endl;
            cout << "Approach: " << myPairE.second << endl;
            // getting the variables from the electorates stances and displaying them

            for (int z = 0; z < numCan; z++) {
                // running through the candidates
//           double distanceOne = 0.0;
                if (eList[x]->getElectoralId() == cList[z]->getCanId()) {
                    // only getting the candidates associated with the correct electorate
                    pair<int, int> myPairC = cList[z]->getStanceOnIssueCan(IList[b]->getIssueName());
                    cout << "Candidate name: " << cList[z]->getCanName() << ": " << endl;
                    cout << "Candidate party: " << cList[z]->getPartyName() << endl;
                    cout << "Significance to Candidate: " << myPairC.first << endl;
                    cout << "Approach: " << myPairC.second << endl << endl;
                    // getting the candidates stances and displaying them

                    double sigDistance = (pow(myPairE.first - myPairC.first, 2)) +
                                         (pow(myPairE.second - myPairC.second, 2));
                    double distanceOne = sqrt(sigDistance);
                    // calculating the Average Stance Euclidean distance for all the candidates and the issues

                    cout << "Average stance Euclidean distance is : " << distanceOne << endl << endl;
                    // displaying the calculation

                    if (distanceOne < winningStance) {
                        // the distance has to be the lowest of the calculations if it is then the index in the for loop will be saved
                        winningStance = distanceOne;
                        winningIndex = z;
                    } //end if
                } // end if
            } // end for

            if (winningIndex != -1) {
                // where the winning index will be sent, if it is sent here then the candidate will get 3 points.
                // as this is the most important aspect
                cList[winningIndex]->setPoints(3);
                cout << "Candidate: " << cList[winningIndex]->getCanName()
                     << " Won 3 points because they were most in touch with their community" << endl
                     << endl;
            } // end if
        }
        cout << "__________________________________________________________________" << endl << endl;
    }

    cout << "Now we calculate the total popularity of the candidate!!" << endl;
    for (int i = 0; i < numE; i++) {
        // for loop to run through the amount of electorates
        int winningIndex = -1;
        int winningLeaderIn = -1;
        // the winning index needs to be reset every time
        int winningLPop = 0;
        int winningCanPop = 0;
        // the wining can / leader pop must be reset every time

        cout << "Electorate name: " << eList[i]->getElectorateName() << endl;
        for (int k = 0; k < numCan; k++) {
            // for loop to run through the amount of candidates
            if (eList[i]->getElectoralId() == cList[k]->getCanId()) {
                // have to make sure it only grabs the candidates associated with the electorate

                int candidatePopTotal = 0;
                // resetting the candidate pop total

                cout << "Candidate Name: " << cList[k]->getCanName() << endl;
                cout << "Candidate Popularity: " << cList[k]->getCanPopularity() << endl;
                cout << "Candidate points: " << cList[k]->getPoints() << endl;

                candidatePopTotal = cList[k]->getCanPopularity();

                if (candidatePopTotal > winningCanPop) {
                    winningCanPop = candidatePopTotal;
                    winningIndex = k;
                    // if statement to get the highest total popularity
                } //end if

                for (int a = 0; a < numParty; a++) {
                    // for loop to run through the total parties
                    int candidateLeaderPopTotal = 0;
                    if (cList[k]->getPartyID() == lList[a]->getPartyID()) {
                        // the leader must be associated with the party
                        cout << "Party: " << pList[a]->getPartyName() << endl;
                        cout << "Leader Name: " << lList[a]->getLeaderName() << endl;
                        cout << "Leader Popularity: " << lList[a]->getLPopularity() << endl << endl;
                        // displaying the values

                        candidateLeaderPopTotal = lList[a]->getLPopularity();
                        //running the loop to get the variables

                        if (candidateLeaderPopTotal > winningLPop) {
                            winningLPop = candidateLeaderPopTotal;
                            winningLeaderIn = k;
                            // the winning leader pop gives the index to the candidate
                        } // end if
                    } // end if
                } // end for
            } // end if
        } // end for

        if (winningIndex != -1) {
            cList[winningIndex]->setPoints(2);
            cout << "Candidate: " << cList[winningIndex]->getCanName() << " Won 2 point due to their popularity"
                 << endl
                 << endl;
            // if statement to get the winning index and add points to the candidate
        } // end if

        if (winningLeaderIn != -1) {
            cList[winningLeaderIn]->setPoints(1);
            cout << "Candidate: " << cList[winningLeaderIn]->getCanName()
                 << " Won 1 point due to leadership popularity"
                 << endl << endl;
            // if statement to get the winning index and add it to the candidate
        } // end if
        /*
         these 2 if statements are done because of an annoying bug that puts more points into leader or can if the next candidate
         in the for loop has higher stats
         */
    } // end for

    for (int z = 0; z < numE; z++) {
        int maxPoint = -1;
        vector<Candidate *> winningCandidates;
        // vector is put in here so that if there are 2 candidates with the same points they can bot give points to their party
        // ive even had all three candidates have the same points

        cout << "__________ELECTORATE " << eList[z]->getElectorateName() << "________________" << endl;
        for (int c = 0; c < numCan; c++) {
            if (cList[c]->getCanId() == eList[z]->getElectoralId()) {
                // getting the candidates associated with the same electorate
                cout << "Electorate ID: " << eList[z]->getElectoralId() << endl;
                cout << "Candidate Name: " << cList[c]->getCanName() << endl;
                cout << "Candidate points are: " << cList[c]->getPoints() << endl << endl;

                winningPoints = cList[c]->getPoints();

                if (winningPoints > maxPoint) {
                    maxPoint = winningPoints;
                    winningCandidates.clear();
                    winningCandidates.push_back(cList[c]);
                    // getting the max point, clearing the vector if there is already one in there and then adding it
                } else if (winningPoints == maxPoint) {
                    winningCandidates.push_back(cList[c]);
                    // this is where it adds it to the vector if there is any candidate that has teh same points
                    // important as it was annoying me if it only added one
                } // end if
            } // end if
        } // end for

        cout << "[[[[[[[[[[[[[[[WINNER OF ELECTORATE " << eList[z]->getElectoralId() << "]]]]]]]]]]]]]]]]]]]]]] "
             << endl;

        for (Candidate *win: winningCandidates) {
            cout << "Candidate party: " << win->getPartyName() << endl;
            cout << "Candidate Name: " << win->getCanName() << endl;
            cout << "Candidate points are: " << maxPoint << endl;
            cout << "_________________________________________" << endl << endl;

            for (int i = 0; i < numParty; i++) {
                if (pList[i]->getPartyName() == win->getPartyName()) {
                    pList[i]->PoliticalParty::setPartyPoints(1);
                } // end if
            } // end for
        } // end for
    } // end for

    for (PoliticalParty *party: pList) {
        party->displayPoliticalParty();
    }

    hungParliment(n);

    if (!hungParliment(n)) {
        cout << "||||||||||||||||||||||||||||||WINNER|||||||||||||||||||||||||||||||||||||" << endl <<
             endl;
    } else {
        cout << "||||||||||||||||||||||||||||||HUNG PARLIAMENT|||||||||||||||||||||||||||||||||||||" << endl <<
             endl;
    } // end else

    int maxPoint = n / 2;

    vector<PoliticalParty*> winningParty;
    for (PoliticalParty *winner: pList) {

        int pWin = winner->getPartyPoints();
        if (pWin > maxPoint) {
// had to fo 2.0 as if it was just two it pulls up more winners if n = 3
            maxPoint = pWin;
            winningParty.clear();
            winningParty.push_back(winner);
        } else if (pWin == maxPoint) {
// Done so that if a party got over max electorate / 2 but the same as the winner, then it will be a hung parliament
            winningParty.push_back(winner);
        }
    }

    if (!winningParty.empty()) {
        for (PoliticalParty* parliment : winningParty) {
            parliment->displayPoliticalParty();
            // printing the winners from the vector
        } // end for
    } else {
        cout << "Hung parliament: " << endl;
        for (PoliticalParty *partyHung: pList) {
            if (partyHung->getPartyPoints() > 1) {
                partyHung->displayPoliticalParty();
                // this is if the vector is empty it will print every party with more than 1 point
            } // end if
        } // end for
    } // end else

    if (hungParliment(n)) {
        cout << "Congratulations to the winners!! Dont fuck it up! " << endl;
    } else {
        cout << "Congratulations to the winner!! Dont fuck it up! " <<
             endl;
    }
}

bool Election::hungParliment(int &n) {
    bool hung = false;
    // setting the boolean to false

    for (int i = 0; i < numParty; i++) {
        for (int j = i + 1; j < numParty; j++) {
            if (pList[i]->getPartyPoints() == pList[j]->getPartyPoints() &&
                pList[i]->getPartyPoints() <= (n / 2)) {
                // this will only work if there are more than 1 parties, it will break with a true boolean
                // it is going through the loops to get a hung parliament if there are two parties with points over the electorate number /2
                hung = true;
            } // end if
        } // end for
        if (hung) {
            break;
            // if it goes through the two loops and there is only one winner it will break with a false
        } // end if
    } // end for
    return hung;
    // returning true or false
} // end method

void Election::deletePoliticalParties() {
    for (int i = 0; i < numParty; i++) {
        if (pList[i] != nullptr) {
            delete pList[i];
            pList[i] = nullptr;
            // using the if and for to delete the array pointers so the de-constructor can be called
        } // end if
    } // end for
} // end method

void Election::deleteCandidates(int &n) {
    for (int i = 0; i < n; i++) {
        if (cList[i] != nullptr) {
            delete cList[i];
            cList[i] = nullptr;
            // using the if and for to delete the array pointers so the de-constructor can be called
        } // end if
    } // end for
} // end method

void Election::deleteTeam() {
    for (int t = 0; t < numTeam; t++) {
        if (CMList[t] != nullptr) {
            delete CMList[t];
            CMList[t] = nullptr;
            // using the if and for to delete the array pointers so the de-constructor can be called
        } // end if
    } // end for
} // end method

void Election::deleteIssues() {
    for (int i = 0; i < numIssue; i++) {
        if (IList[i] != nullptr) {
            delete IList[i];
            IList[i] = nullptr;
            // using the if and for to delete the array pointers so the de-constructor can be called
        } // end if
    } // end for
} // end method

void Election::deleteElectoralDivions() {
    for (int i = 0; i < numE; i++) {
        if (eList[i] != nullptr) {
            delete eList[i];
            eList[i] = nullptr;
            // using the if and for to delete the array pointers so the de-constructor can be called
        } // end if
    } // end for
} // end method

PoliticalParty::~PoliticalParty() {
    cout << endl << "Political Party: '" << partyName << "' has been deleted" << endl;
}

Candidate::~Candidate() {
    cout << endl << "Candidate: '" << canName << "' has been deleted" << endl;
}

CampaignManagementTeam::~CampaignManagementTeam() {
    cout << endl << "Campaign Team: '" << teamID << "' has been deleted" << endl;
}

Issues::~Issues() {
    cout << endl << "Issue: '" << issueName << "' has been deleted" << endl;
}

Leader::~Leader() {
    cout << endl << "Political Leader: '" << leaderName << "' has been deleted" << endl;
}

ElectoralDivision::~ElectoralDivision() {
    cout << endl << "Electoral Division: '" << electorateName << "' has been deleted" << endl;
}


