//
// Created by Will on 15/09/2023.
//

#ifndef SECONDTRY_HEADER_H
#define SECONDTRY_HEADER_H



#include <iostream>
#include <string>
#include <utility>
#include <vector>


using namespace std;

class Issues {
private:
    string issueName;

public:
    Issues() : issueName() {}
    explicit Issues(string iS) : issueName(std::move(iS)) {}

    string getIssueName();
    void displayIssues();

    ~Issues();
};

class PoliticalParty {
protected:
    int partyID;
    string partyName;
    int politicalStance;
    int politicalLeaning;
    string politicalSlogan;
    int funding;
    int pPoints;

public:
    vector<pair<string, pair<int, int>>> stancesOnIssues;

    PoliticalParty() : partyID(), partyName(), politicalStance(), politicalLeaning(), politicalSlogan(), funding(), pPoints() {}

    PoliticalParty(int pID, string n, int pStance, int pLean, string pSlogan, int f, int p) :
            partyID(pID), partyName(std::move(n)), politicalStance(pStance), politicalLeaning(pLean), politicalSlogan(std::move(pSlogan)),
            funding(f), pPoints(p) {}

     int getPartyID() const;
     string getPartyName() const;
     int getPoliticalStance() const;
     int getPoliticalLeaning() const;
     string getSlogan() const;
     int getFunding() const;
     int getPartyPoints() const;
    void setPartyPoints(int p);

    void setStanceOnIssue(const string& issueName, int significance, int approach);
   pair<int, int> getStanceOnIssue(const string& issueName) const;

    void displayPoliticalParty();
    void displayStancesOnIssues() const;

    ~PoliticalParty();
};

class Leader : public PoliticalParty {
private:
    string leaderName;
    int lPopularity;
    int lPoliticalSkill;
    int lKnowledge;

public:
    Leader() : PoliticalParty(), leaderName(), lPopularity(), lPoliticalSkill(), lKnowledge() {}

    Leader(int pId, string pName, int pStance, int pLean, string pSlogan, int pFunding, int pPoints,
           string lName, int pop, int pSkill, int k) :
            PoliticalParty(pId, std::move(pName), pStance, pLean, std::move(pSlogan), pFunding, pPoints),
            leaderName(std::move(lName)), lPopularity(pop), lPoliticalSkill(pSkill), lKnowledge(k) {}

     string getLeaderName() const;
    int getLPopularity() const;
     int getLPoliticalSkill() const;
     int getLKnowledge() const;
    void setPopularity(int pp);

    void displayPoliticalLeader();

    ~Leader();
};

class Candidate : public PoliticalParty {
private:
    int canID;
    string canName;
    int canPopularity;
    int canPoliticalSkill;
    int canKnowledge;
    int points;

public:
    vector<pair<string, pair<int, int>>> stancesOnIssuesCan;

    Candidate() : PoliticalParty(), canID(), canName(), canPopularity(), canPoliticalSkill(), canKnowledge(), points() {}

    Candidate(int pId, string pName, int pStance, int pLean, string pSlogan, int pFunding, int pPoints, int cId, string cName, int pop,
              int pSkill, int k, int p) :
            PoliticalParty(pId, std::move(pName), pStance, pLean, std::move(pSlogan), pFunding, pPoints), canID(cId), canName(std::move(cName)),
            canPopularity(pop),
            canPoliticalSkill(pSkill), canKnowledge(k), points(p) {}

    void displayPoliticalCandidate();
    void setStanceOnIssueCan(const string& issueName, int significance, int approach);
     pair<int, int> getStanceOnIssueCan(const string& issueName) const;
     string getCanName() const;
     int getCanId() const;
     int getCanPopularity() const;
    int getCanPoliticalSkill() const;
     int getCanKnowledge() const;
     int getPoints() const;
    void setPoints(int lp);
    void setPopularity(int cp);
    void displayStancesOnIssuesCan();

    ~Candidate();
};

class CampaignManagementTeam : public PoliticalParty {
private:
    int teamID;
    int strategicSkill;
    int organisationalSkill;
    int size;

public:
    CampaignManagementTeam() : PoliticalParty(), teamID(), strategicSkill(), organisationalSkill(), size() {}

    CampaignManagementTeam(int pId, string pName, int pStance, int pLean, string pSlogan, int pFunding, int pPoints, int tID, int cmtSkill, int OS,
                           int s) :
            PoliticalParty(pId, std::move(pName), pStance, pLean, std::move(pSlogan), pFunding, pPoints),
            teamID(tID), strategicSkill(cmtSkill), organisationalSkill(OS), size(s) {}

     int getTeamId() const;
     int getStrategicSkill() const;
     int getOrganisationalSkill() const;
   int getSize() const;
    void displayTeam();

    ~CampaignManagementTeam();
};

class ElectoralDivision {
private:
    int electoralID;
    string electorateName;
    int amountOfCitizens;
    int eLeaning; // I am designing the leaning to make 1 left leaning and 10 right leaning
    vector<pair<string, pair<int, int>>> stancesOnIssues;

public:
    ElectoralDivision() : electoralID(), electorateName(), amountOfCitizens(), eLeaning() {}
    ElectoralDivision(int eID, string eName, int amountC, int eL) :
    electoralID(eID), electorateName(std::move(eName)), amountOfCitizens(amountC), eLeaning(eL) {}

    void setStanceOnIssue(const string& issueName, int significance, int approach);
     pair<int, int> getStanceOnIssue(const string& issueName) const;

     int getElectoralId() const;
     const string &getElectorateName() const;
     int getAmountOfCitizens() const;
     int getELeaning() const;

    void displayElecorates() const;
    void displayStancesOnIssues() const;

    ~ElectoralDivision();
};

class Election {
public:

    void generateIssues();
    void generatePoliticalParties();
    void generatePoliticalLeader();
    int generatePoliticalCandidate(int n);
    void generateCampaignTeam();
    void generateElectorate(int &n);
    void displayAllGeneratedInformation(int &n, int &eNumber);
    void generateCampaignEvents(int &m, int &n);
    void generateDebate(ElectoralDivision& division, string& campaignDay);
    void generateCandidateEvent(ElectoralDivision& division, int& count, string& campaignDay);
    void generateLeaderEvent(ElectoralDivision& division, int& count, string& campaignDay);
    void generateIssueEvent(ElectoralDivision& division, int& count);
    bool hungParliment(int& n);
    void decideWinner(int& m, int& n);
    void deletePoliticalParties();
    void deleteCandidates(int &n);
    void deleteTeam();
    void deleteIssues();
    void deleteElectoralDivions();
};

#endif //SECONDTRY_HEADER_H