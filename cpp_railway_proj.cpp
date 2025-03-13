//
//  main.cpp
//  dsfinal
//
//  Created by Madhav Sharma on 23/07/23.
//


#include<iostream>
#include<string>
#include<vector>
#include<time.h>
#include<cctype>
#include<iomanip>
#include<algorithm>
#include <sstream>
#include<fstream>

using namespace std;


void admin(){
    cout.width(149);
    cout<<right;}

void adminmode(){
    admin();
    cout<<"Login Succesful\n";
    admin();
    cout<<"Menu\n";
    admin();
    cout<<"Click 1 for History of trains\n";
    admin();
    cout<<"Click 2 for Deletion of History \n";
    admin();
    cout<<"Click 3 for Logging out of Admin Mode\n";
    admin();
    cout<<"Enter your Choice : ";
}



//Find in Array
bool sn(const std::string& user_input, const std::vector<std::vector<std::string>>& arrays) {
    for (const auto& array : arrays) {
        if (std::find(array.begin(), array.end(), user_input) != array.end()) {
            return true;}}
    return true;}


//LowerCase CHARACTER
char toLowerCase(char c) {
    if(c<='A' && c <= 'Z' ) {
        return c + 32;
    }
    return c;
}

//lowercase STRING
std::string lc(const std::string& input) {
    std::string result;
    for (char c : input) {
        result.push_back(tolower(c));
    }
    return result;
}


//reads train number from string
 bool tt(const string& str, int number) {
     std::stringstream ss(str);
     int num;
     while (ss >> num) {
         if (num == number) {
             return true;
         }
     }
     return false;
 }

 
//print of reverse trains//print of reverse trains//print of reverse trains//print of reverse trains//print of reverse trains//print of reverse trains//print of reverse trains
void printv(const std::vector<std::vector<std::string>>& rarrays, int searchNumber,const std::vector<std::vector<std::string>>& deprarrays,const std::vector<std::vector<std::string>>& arrivalrarrays)
{
    for (const auto& innerVector : rarrays) {
        if (!innerVector.empty() && tt(innerVector[0], searchNumber)) {
            int temphere=1;
            int n=0;
            for (auto i = innerVector.begin() + 1; i != innerVector.end(); ++i) {
                cout <<"┃  ";
                cout.width(2);
                cout<<left;
                cout<<temphere<<".";
                cout.width(2);
                cout<<left;
                cout<<" ┃ ";
                cout<<right;
                cout.width(35);
                cout<<left;
                cout<<*i ;
                temphere++;
                
                for (const auto& innerVector1 : arrivalrarrays) {
                    if (!innerVector1.empty() && tt(innerVector1[0], searchNumber)){
                        for (auto k = innerVector1.begin() + 1; k != innerVector1.end(); k++) {
                            
                            cout.width(5);
                            cout<<left;
                            cout<<"┃";
                            
                            cout.width(16);
                            cout<<left;
                            cout<<k[n];
                            break;
                        }
                        
                        for (const auto& innerVector1 : deprarrays) {
                            if (!innerVector1.empty() && tt(innerVector1[0], searchNumber)){
                                for (auto j = innerVector1.begin() + 1; j != innerVector1.end(); j++) {
                                    cout.width(3);
                                    cout<<left;
                                    cout<<"┃   ";
                                    cout.width(17);
                                    cout<<j[n];
                                    cout.width(10);
                                    cout<<left;
                                    cout<<"┃";
                                    cout<<endl;
                                    n++;
                                    break;
                                    
                                }}}}}}}}}


                      

//print of  trains//print of  trains//print of  trains//print of  trains//print of  trains//print of  trains//print of  trains//print of  trains//print of  trains
void printv1(const std::vector<std::vector<std::string>>& arrays, int searchNumber,const std::vector<std::vector<std::string>>& deparrays,const std::vector<std::vector<std::string>>& arrivalarrays)
{
    for (const auto& innerVector : arrays) {
        if (!innerVector.empty() && tt(innerVector[0], searchNumber)) {
            int temp=1;
            int n=0;
            for (auto i = innerVector.begin() + 1; i != innerVector.end(); ++i) {
                cout <<"┃  ";
                cout.width(2);
                cout<<left;
                cout<<temp<<".";
                cout.width(2);
                cout<<left;
                cout<<" ┃ ";
                cout<<right;
                cout.width(35);
                cout<<left;
                cout<<*i ;
                temp++;
                
                for (const auto& innerVector1 : arrivalarrays) {
                    if (!innerVector1.empty() && tt(innerVector1[0], searchNumber)){
                        for (auto k = innerVector1.begin() + 1; k != innerVector1.end(); k++) {
                            
                            cout.width(5);
                            cout<<left;
                            cout<<"┃";
                            
                            cout.width(16);
                            cout<<left;
                            cout<<k[n];
                            break;
                        }
                        
                        for (const auto& innerVector1 : deparrays) {
                            if (!innerVector1.empty() && tt(innerVector1[0], searchNumber)){
                                for (auto j = innerVector1.begin() + 1; j != innerVector1.end(); j++) {
                                    cout.width(3);
                                    cout<<left;
                                    cout<<"┃   ";
                                    cout.width(17);
                                    cout<<j[n];
                                    cout.width(10);
                                    cout<<left;
                                    cout<<"┃";
                                    cout<<endl;
                                    n++;
                                    break;
                                    
                                }}}}}}}}}

    
int main()
{int x,trn;
    
    
    
    //Destination arrays  //Destination arrays //Destination arrays //Destination arrays //Destination arrays //Destination arrays //Destination arrays
       std::vector<std::vector<std::string>> arrays = {
        
        {"19225 - Bhagat ki Kothi - Jammu Tawi Express", "verka", "batala", "dhariwal", "gurdaspur", "pathankot", "hira nagar", "jammu tawi"},
        
        {"19326 - Amritsar - Indore Bi-Weekly Express","amritsar", "beas", "jalandhar city", "dhandari kalan", "sirhind", "ambala cant", "yamunanagar jagadhri", "saharanpur", "deoband", "muzaffarnagar", "meerut city", "ghaziabad", "hazrat nizamuddin", "faridabad", "mathura", "raja ki mandi", "agra cant", "gwalior", "shivpuri", "guna", "ruthiyai", "biyavra rajgarh", "shajapur", "maksi", "dewas", "indore"},
        
        {"19226 - Jammu Tawi - Bhagat ki Kothi Express", "beas", "jalandhar city", "kapurthala", "sultanpur lodi", "lohian khas", "makhu", "firozpur cant", "faridkot", "kot kapura", "gangsar jaitu", "bhatinda", "mandi dabwali", "sangaria", "hanumangarh", "pili bangan", "suratgarh", "lalgarh", "bikaner", "nokha", "nagaur", "merta road", "gotan", "jodhpur", "bhagat ki kothi"},
        
        {"12204 - Amritsar - Saharsa Garib Rath Express ","amritsar", "beas", "jalandhar city", "phagwara", "dhandari kalan", "ambala cant", "new delhi", "hapur", "moradabad", "bareilly", "hardoi", "lucknow nr", "gorakhpur", "siwan", "chhapra", "hajipur", "muzaffarpur", "samastipur", "dalsingh sarai", "barauni", "begu sarai", "khagaria", "simri bakhtiyarpur", "saharsa"},
        
        {"22126 - Amritsar - Nagpur AC SF Express","amritsar", "beas", "jalandhar city", "ludhiana", "ambala cant", "new delhi", "agra cant", "gwalior", "virangana lakshmibai jhansi", "bhopal", "nagpur" },
        
        {"12014 - Amritsar - New Delhi Shatabdi Express","amritsar", "beas", "jalandhar city", "phagwara", "ludhiana", "sirhind", "ambala cant", "new delhi"},
        
        {"12242 - Amritsar - Chandigarh SF Express","amritsar", "beas", "jalandhar city", "phagwara", "ludhiana", "mohali", "chandigarh"},
        
        {"12716 - Sachkhand Express","amritsar", "beas", "jalandhar city", "phagwara", "ludhiana", "khanna", "sirhind", "rajpura", "ambala cant", "kurukshetra", "karnal", "panipat", "new delhi", "faridabad", "mathura", "agra cant", "dhaulpur", "morena", "gwalior", "dabra", "virangana lakshmibai jhansi", "lalitpur", "bina", "bhopal", "itarsi", "khandwa", "burhanpur", "bhusaval", "jalgaon", "pachora", "chalisgaon", "manmad", "aurangabad", "jalna", "selu", "parbhani", "purna", "hazur sahib nanded"},
        
        {"12318 - Akal Takht Express ", "amritsar", "beas", "jalandhar city", "ludhiana", "sirhind", "ambala cant", "saharanpur", "najibabad", "moradabad", "bareilly", "lucknow", "sultanpur", "varanasi", "dd upadhyaya", "patna", "patna saheb", "mokameh", "kiul", "jhajha", "jasidih", "madhupur", "asansol", "kolkata"},
        
        {"12358 - Durgiana Express","amritsar", "beas", "jalandhar city", "ludhiana", "ambala cant", "saharanpur", "moradabad", "bareilly", "lucknow", "varanasi", "dd upadhyaya", "sasaram", "gaya", "parasnath", "dhanbad", "asansol", "kolkata"},
        
        {"12484 - Amritsar - Kochuveli Weekly SF Express","amritsar", "beas", "jalandhar city", "ludhiana", "ambala cant", "new delhi", "hazrat nizamuddin", "kota", "ratlam", "vadodara", "surat", "vasai road", "panvel", "chiplun", "ratnagiri", "madgaon", "udupi", "mangalore", "kasaragod", "kannur", "kozhikkode", "shoranur", "thrisur", "ernakulam", "alleppey", "kayankulam", "kollam", "kochuveli"},
        
        {"14616 - Amritsar - Lal Kuan Express","amritsar", "beas", "jalandhar city", "phagwara", "dhandari kalan", "new morinda", "mohali", "chandigarh", "ambala cant", "yamunanagar jagadhri", "saharanpur", "roorkee", "laksar", "najibabad", "moradabad", "kashipur", "bazpur", "lal kuan"},
        
        {"12460 - Amritsar - New Delhi InterCity Express","amritsar", "beas", "jalandhar city", "jalandhar cant", "phagwara", "phillaur", "dhandari kalan", "sirhind", "rajpura", "ambala city", "ambala cant", "kurukshetra", "karnal", "panipat", "sonipat", "subzi mandi", "new delhi"},
        
        {"14618 - Amritsar - Banmankhi Jan Sewa Express (UnReserved)","amritsar", "beas", "jalandhar city", "phagwara", "phillaur", "ludhiana", "dhandari kalan", "sirhind", "rajpura", "ambala cant", "yamunanagar jagadhri", "saharanpur", "laksar", "najibabad", "seohara", "moradabad", "rampur", "bareilly", "maikalganj", "sitapur", "burhwal", "gonda", "basti", "gorakhpur", "deoria sadar", "bhatni", "mairwa", "siwan", "ekma", "chhapra", "dighwara", "sonpur", "hajipur", "akshaywat rai nagar", "desari", "mehnar road", "shahpur patoree", "mohiuddinnagar", "vidyapatidham", "bachwara", "barauni", "begu sarai", "lakhminia", "khagaria", "mansi", "koparia", "s bhakhtiyarpur", "saharsa", "dauram madhepura", "murliganj", "banmankhi"},
        
        {"12054 - Amritsar - Haridwar Jan Shatabdi Express","amritsar", "beas", "jalandhar city", "phagwara", "dhandari kalan", "sirhind", "ambala cant", "yamunanagar jagadhri", "saharanpur", "roorkee", "haridwar"},
        
        {"12926 - Paschim SF Express ","amritsar", "beas", "jalandhar city", "jalandhar cant", "phagwara", "ludhiana", "mohali", "chandigarh", "ambala cant", "kurukshetra", "karnal", "panipat", "sonipat", "subzi mandi", "new delhi", "faridabad", "mathura", "bharatpur", "bayana", "hindaun city", "gangapur city", "sawai madhopur", "kota", "ramganj mandi", "shamgarh", "nagda", "ratlam", "meghnagar", "dahod", "godhra", "vadodara", "bharuch", "surat", "navsari", "valsad", "vapi", "dahanu road", "borivali", "mumbai"},
        
        {"15708 - Amrapali Express","amritsar", "jandiala", "beas", "jalandhar city", "jalandhar cant", "phagwara", "phillaur", "ludhiana", "khanna", "sirhind", "rajpura", "ambala cant", "karnal", "panipat", "sonipat", "subzi mandi", "delhi", "khurja", "aligarh", "hathras", "tundla", "firozabad", "etawah", "kanpur", "unnao", "aishbagh", "badshahnagar", "barabanki", "gonda", "mankapur", "basti", "khalilabad", "gorakhpur", "deoria sadar", "mairwa", "siwan", "chhapra", "dighwara", "sonpur", "hajipur", "muzaffarpur", "dholi", "khudiram bose pusa", "samastipur", "barauni", "begu sarai", "khagaria", "mansi", "thana bihpur", "naugachia", "kursela", "karagola road", "katihar"},
        
        {"18101 - Tatanagar - Jammu Tawi Express ", "batala", "dhariwal", "gurdaspur", "dinanagar", "pathankot ", "hira nagar", "vijaypur jammu", "jammu tawi"},
        
        {"18309 - Sambalpur - Jammu Tawi Express", "batala", "dhariwal", "gurdaspur", "dinanagar", "pathankot", "hira nagar", "vijaypur jammu", "jammu tawi"},
        
        {"04654 - Amritsar - New Jalpaiguri Clone SF Special","amritsar", "saharanpur", "moradabad", "sitapur", "gorakhpur", "chhapra", "muzaffarpur", "samastipur", "katihar", "new jalpaiguri"},
        
        {"11058 - Amritsar - Mumbai CSMT Express","amritsar", "jandiala", "beas", "kartarpur", "jalandhar city", "jalandhar cant", "phagwara", "phillaur", "ludhiana", "ahmedgarh", "malerkotla", "dhuri", "nabha", "patiala", "rajpura", "ambala city", "ambala cant", "shahabad markanda", "kurukshetra", "nilokheri", "taraori", "karnal", "gharaunda", "panipat", "samalkha", "ganaur", "sonipat", "rathdhana", "narela", "adarsh nagar delhi", "subzi mandi", "new delhi", "hazrat nizamuddin", "faridabad", "ballabgarh", "palwal", "kosi kalan", "mathura", "agra cant", "dhaulpur", "morena", "gwalior", "dabra", "datia", "virangana lakshmibai jhansi", "babina", "talbahat", "lalitpur", "dhaura", "bina", "mandi bamora", "ganj basoda", "gulabganj", "vidisha", "bhopal", "rani kamlapati", "mandi dip", "obaidulla ganj", "budni", "narmadapuram", "itarsi", "banapura", "timarni", "harda", "khirkiya", "chhanera", "talvadya", "khandwa", "nepanagar", "burhanpur", "raver", "savda", "bhusaval", "jalgaon", "pachora", "chalisgaon", "manmad", "nasik road", "devlali", "kalyan", "thane", "dadar", "csmt"},
        
        {"22430 - Pathankot - Delhi SF Express", "beas", "jalandhar city", "ludhiana", "sirhind", "ambala cant", "kurukshetra", "karnal", "panipat", "sonipat", "subzi mandi", "delhi"},
        
        {"12408 - Amritsar - New Jalpaiguri Karmabhoomi Express (UnReserved)","amritsar", "beas", "jalandhar city", "ludhiana", "ambala cant", "saharanpur", "moradabad", "sitapur", "gorakhpur", "deoria sadar", "siwan", "chhapra", "hajipur", "muzaffarpur", "samastipur", "khagaria", "katihar", "barsoi", "new jalpaiguri"},
        
        {"04652 - Amritsar - Jaynagar Clone Special","amritsar", "ambala cant", "delhi", "moradabad", "lucknow", "shahganj", "chhapra", "muzaffarpur", "samastipur", "darbhanga", "jaynagar"},
        
        {"18104 - Amritsar - Tatanagar Jallianwala Bagh Express","amritsar", "beas", "jalandhar city", "ludhiana", "ambala cant", "yamunanagar jagadhri", "saharanpur", "roorkee", "laksar", "moradabad", "bareilly", "lucknow", "ayodhya cant", "shahganj", "varanasi", "dd upadhyaya", "bhabua road", "sasaram", "dehri on son", "anugrah narayan road", "rafiganj", "gaya", "koderma", "gomoh", "bokaro stl city", "purulia", "tatanagar"},
        
        {"22446 - Amritsar - Kanpur Central bi-weekly SF Express","amritsar", "beas", "jalandhar city", "phagwara", "ludhiana", "rajpura", "ambala cant", "saharanpur", "roorkee", "laksar", "moradabad", "bareilly", "unnao", "kanpur"},
        
        {"22424 - Amritsar - Gorakhpur Jansadharan SF Express(UnReserved)","amritsar", "beas", "jalandhar city", "phagwara", "ludhiana", "ambala cant", "saharanpur", "moradabad", "bareilly", "shahjehanpur", "sitapur", "gonda", "mankapur", "basti", "khalilabad", "gorakhpur"},
        
        {"14650 - Saryu Yamuna Express","amritsar", "beas", "kartarpur", "jalandhar city", "jalandhar cant", "phagwara", "phillaur", "ludhiana", "khanna", "mandi gobind garh", "sirhind", "rajpura", "ambala city", "ambala cant", "yamunanagar jagadhri", "saharanpur", "roorkee", "laksar", "najibabad", "kanth", "moradabad", "rampur", "bareilly", "shahjehanpur", "lucknow", "barabanki", "ayodhya cant", "ayodhya", "akbarpur", "shahganj", "khorason road", "azamgarh", "muhammadabad", "mau", "indara", "rasra", "ballia", "suraimanpur", "chhapra", "hajipur", "muzaffarpur", "samastipur", "haiaghat", "laheria sarai", "darbhanga", "sakri", "madhubani", "rajnagar", "khajauli", "jaynagar"},
        
        {"14674 - Shaheed Express","amritsar", "beas", "kartarpur", "jalandhar city", "jalandhar cant", "phagwara", "phillaur", "ludhiana", "khanna", "mandi gobind garh", "sirhind", "rajpura", "ambala city", "ambala cant", "yamunanagar jagadhri", "saharanpur", "roorkee", "laksar", "najibabad", "kanth", "moradabad", "rampur", "bareilly", "shahjehanpur", "lucknow", "barabanki", "ayodhya cant", "ayodhya", "akbarpur", "shahganj", "khorason road", "azamgarh", "muhammadabad", "mau", "indara", "rasra", "ballia", "suraimanpur", "chhapra", "hajipur", "muzaffarpur", "samastipur", "haiaghat", "laheria sarai", "darbhanga", "sakri", "madhubani", "rajnagar", "khajauli", "jaynagar"},
        
        {"19612 - Amritsar - Ajmer Express (via Firozpur)","amritsar", "beas", "jalandhar city", "phagwara", "ludhiana", "jagraon", "moga", "talwandi", "firozpur cant", "faridkot", "kot kapura", "gangsar jaitu", "bhatinda", "kalanwali", "sirsa", "hisar", "bhiwani", "rewari", "khairthal", "alwar", "rajgarh", "baswa", "bandikui", "dausa", "getor jagatpura", "gandhinagar jaipur", "jaipur", "kishangarh", "ajmer"},
        
        {"14604 - Amritsar - Saharsa Jansadharan Express (Via Sirhind) (UnReserved)","amritsar", "beas", "jalandhar city", "ludhiana", "sirhind", "ambala cant", "saharanpur", "najibabad", "dhampur", "moradabad", "bareilly", "shahjehanpur", "sitapur", "burhwal", "gonda", "mankapur", "basti", "khalilabad", "gorakhpur", "deoria sadar", "siwan", "chhapra", "sonpur", "hajipur", "muzaffarpur", "samastipur", "rusera ghat", "hasanpur road", "salauna", "khagaria", "mansi", "dhamara ghat", "simri bhakhtiyarpur", "saharsa"},
        
        {"12380 - Amritsar - Sealdah Jallianwala Bagh Express","amritsar", "beas", "jalandhar city", "ludhiana", "ambala cant", "delhi", "kanpur", "dd upadhyaya", "sasaram", "gaya", "dhanbad", "kumardubi", "asansol", "durgapur", "barddhaman", "sealdah"},
        
        {"14505 - Amritsar - Nangal Dam Express","amritsar", "beas", "jalandhar city", "ludhiana", "samrala", "new morinda", "morinda", "kurali", "roop nagar", "kiratpur sahib", "anandpur sahib", "nangal dam"},
        
        {"12422 - Amritsar - Hazur Sahib Nanded SF Express","amritsar", "beas", "jalandhar city", "phagwara", "ludhiana", "dhuri", "sangrur", "jakhal", "narwana", "rohtak", "new delhi", "agra cant", "gwalior", "virangana lakshmibai jhansi", "bina", "bhopal", "itarsi", "khandwa", "malkapur", "shegaon", "akola", "washim", "hingoli", "purna", "hazur sahib nanded"},
        
        {"12498 - Shan-e-Punjab Express","amritsar", "beas", "jalandhar city", "phagwara", "dhandari kalan", "khanna", "rajpura", "ambala cant", "kurukshetra", "karnal", "panipat", "sonipat", "subzi mandi", "new delhi"},
        
        {"15934 - Amritsar - New Tinsukia Express ","amritsar", "beas", "jalandhar city", "ludhiana", "ambala cant", "saharanpur", "moradabad", "bareilly", "shahjehanpur", "lucknow", "ayodhya cantt", "akbarpur", "varanasi", "ghazipur city", "ballia", "chhapra", "hajipur", "desari", "barauni", "khagaria", "katihar", "new jalpaiguri", "new cooch behar", "new alipurduar", "new bongaigaon", "rangia", "guwahati", "chaparmukh", "hojai", "lanka", "lumding", "diphu", "dimapur", "furkating", "mariani", "simaluguri", "new tinsukia"},
        
        {"22429 - Delhi - Pathankot SF Express", "batala", "dhariwal", "gurdaspur", "dinanagar", "pathankot"},
        
        {"18238 - Chhattisgarh Express ","amritsar", "jandiala", "beas", "jalandhar city", "jalandhar cant", "phagwara", "phillaur", "ludhiana", "sanahwal", "doraha", "chawapail", "khanna", "mandi gobind garh", "sirhind", "rajpura", "ambala city", "ambala cant", "barara", "jagadhri workshop", "yamunanagar jagadhri", "saharanpur", "deoband", "muzaffarnagar", "khatauli", "daurala", "meerut cant", "meerut city", "modinagar", "guldhar", "ghaziabad", "sahibabad", "hazrat nizamuddin", "ballabgarh", "palwal", "kosi kalan", "chata", "mathura", "raja ki mandi", "agra cant", "dhaulpur", "morena", "gwalior", "dabra", "datia", "virangana lakshmibai jhansi", "babina", "basai", "talbahat", "lalitpur", "bina", "mandi bamora", "ganj basoda", "vidisha", "bhopal", "rani kamlapati", "obaidulla ganj", "narmadapuram", "itarsi", "ghoradongri", "betul", "amla", "multai", "pandhurna", "narkher", "nagpur","kamptee", "bhandara road", "tumsar road", "tirora", "gondia", "amgaon", "salekasa", "dongargarh", "raj nandgaon", "durg", "bhilai power house", "raipur", "tilda", "bhatapara", "belha", "chakarbhatha", "bilaspur"},
        
        {"12032 - Amritsar - New Delhi Shatabdi Express","amritsar", "beas", "jalandhar city", "phagwara", "ludhiana", "rajpura", "ambala cant", "new delhi"},
        
        {"12030 - Amritsar - New Delhi Swarna Jayanti Shatabdi Express","amritsar", "beas", "jalandhar city", "phagwara", "ludhiana", "rajpura", "ambala cant", "new delhi"},
        
        {"12412 - Amritsar - Chandigarh Intercity Express","amritsar", "beas", "jalandhar city", "phagwara", "ludhiana", "samrala", "new morinda", "kharar", "mohali", "chandigarh"},
        
        {"19614 - Amritsar - Ajmer Express (via Dhuri) ","amritsar", "beas", "jalandhar city", "phagwara", "ludhiana", "malerkotla", "dhuri", "sangrur", "jakhal", "hisar", "bhiwani", "rewari", "khairthal", "alwar", "rajgarh", "baswa", "bandikui", "dausa", "getor jagatpura", "gandhinagar jaipur", "jaipur", "kishangarh", "ajmer"},
        
        {"15532 - Amritsar - Saharsa Jansadharan Express (Via Chandigarh) (UnReserved)" ,"amritsar", "beas", "jalandhar city", "ludhiana", "chandigarh", "ambala cant", "saharanpur", "laksar", "moradabad", "bareilly", "sitapur", "gonda", "basti", "gorakhpur", "deoria sadar", "bhatni", "siwan", "chhapra", "sonpur", "hajipur", "muzaffarpur", "samastipur", "rusera ghat", "hasanpur road", "khagaria", "mansi", "s bhakhtiyarpur", "saharsa"},
        
        {"19416 - Shri Mata Vaishno Devi Katra - Ahmedabad Express", "beas", "jalandhar city", "firozpur cant", "bhatinda", "sirsa", "hisar", "bhiwani", "rewari", "khairthal", "alwar", "bandikui", "dausa", "gandhinagar jaipur", "jaipur", "phulera", "kishangarh", "ajmer", "beawar", "marwar", "rani", "falna", "abu road", "palanpur", "mahesana", "sabarmati bg", "ahmedabad"},
        
        {"14654 - Amritsar - Hisar Express","amritsar", "beas", "kartarpur", "jalandhar city", "phagwara", "phillaur", "ludhiana", "malerkotla", "dhuri", "sangrur", "jakhal", "hisar"},
        
        {"13006 - Amritsar - Howrah Mail","amritsar", "beas", "kartarpur", "jalandhar city", "jalandhar cant", "phagwara", "ludhiana", "rajpura", "ambala cant", "yamunanagar jagadhri", "saharanpur", "roorkee", "laksar", "najibabad", "nagina", "dhampur", "moradabad", "rampur", "bareilly", "shahjehanpur", "hardoi", "balamau", "lucknow", "bachhrawn", "rae bareli", "jais", "gauriganj", "amethi", "partapgarh", "badshahpur", "janghai", "bhadohi", "varanasi", "kashi", "dd upadhyaya", "zamania", "dildarnagar", "gahmar", "buxar", "dumraon", "ara", "danapur", "patna", "patna saheb", "simri bakhtiyarpur", "mokameh", "kiul", "jhajha", "jasidih", "madhupur", "chittaranjan", "asansol", "raniganj", "durgapur", "barddhaman", "howrah"},
        
        {"12904 - Golden Temple Mail ","amritsar", "beas", "jalandhar city", "ludhiana", "ambala cant", "yamunanagar jagadhri", "saharanpur", "muzaffarnagar", "sakhoti tanda", "meerut cant", "meerut city", "ghaziabad", "hazrat nizamuddin", "faridabad", "mathura", "bharatpur", "bayana", "hindaun city", "shrimahaveerji", "gangapur city", "sawai madhopur", "kota", "ramganj mandi", "bhawani mandi", "shamgarh", "nagda", "ratlam", "meghnagar", "dahod", "godhra", "vadodara", "surat", "borivali", "mumbai"},
        
        {"15212 - Jan Nayak Express (UnReserved)","amritsar", "beas", "jalandhar city", "phagwara", "phillaur", "ludhiana", "dhandari kalan", "sirhind", "rajpura", "ambala cant", "yamunanagar jagadhri", "saharanpur", "laksar", "najibabad", "moradabad", "bareilly", "shahjehanpur", "maikalganj", "sitapur city", "sitapur", "burhwal", "gonda", "basti", "gorakhpur", "kaptanganj", "ghughuli", "siswa bazar", "khada", "bagaha", "harinagar", "narkatiaganj", "chanpatia", "bettiah", "sagauli", "bapudm motihari", "pipra", "chakia", "mehsi", "motipur", "muzaffarpur", "dholi", "karpoorigram", "samastipur", "laheria sarai", "darbhanga"},
        
        {"18310 - Jammu Tawi - Sambalpur Express", "jandiala", "beas", "jalandhar city", "jalandhar cant", "phagwara", "phillaur", "ludhiana", "chandigarh", "ambala cant", "shahabad markanda", "kurukshetra", "karnal", "panipat", "sonipat", "subzi mandi", "delhi", "ghaziabad", "aligarh", "hathras", "tundla", "shikohabad", "etawah", "jhinjhak", "kanpur central", "fatehpur", "prayagraj", "meja road", "vindhyachal", "mirzapur", "chunar", "sonbhadra", "chopan", "renukut", "dudhinagar", "wyndhamganj", "nagaruntari", "garhwa", "garwa road", "daltonganj", "barwadih", "latehar", "tori", "khalari", "patratu", "barka kana", "ramgarh cantt", "muri", "ranchi", "hatia", "govindpur road", "bano", "orga", "rourkela", "rajgangpur", "jharsuguda", "rengali", "sambalpur"},
        
        {"18102 - Jammu Tawi - Tatanagar Express", "jandiala", "beas", "jalandhar city", "jalandhar cant", "phagwara", "phillaur", "ludhiana", "chandigarh", "ambala cant", "shahabad markanda", "kurukshetra", "karnal", "panipat", "sonipat", "subzi mandi", "delhi", "ghaziabad", "aligarh", "hathras", "shikohabad", "etawah", "jhinjhak", "kanpur central", "fatehpur", "prayagraj", "meja road", "vindhyachal", "mirzapur", "chunar", "sonbhadra", "chopan", "renukut", "dudhinagar", "wyndhamganj", "nagaruntari", "garhwa", "garwa road", "daltonganj", "barwadih", "latehar", "tori", "khalari", "patratu", "barka kana", "ramgarh cantt", "muri", "chandil", "tatanagar"},
        
        {"14632 - Amritsar - Dehradun Express","amritsar", "jandiala", "beas", "jalandhar city", "jalandhar cant", "phagwara", "phillaur", "ludhiana", "new morinda", "chandigarh", "ambala cant", "jagadhri workshop", "yamunanagar jagadhri", "saharanpur", "roorkee", "laksar", "pathri", "ikkar h", "jwalapur", "haridwar", "motichur", "raiwala", "kansrao", "doiwala", "harrawala", "dehradun"},
        
        {"19415 - Ahmedabad - Shri Mata Vaishno Devi Katra Express", "batala","pathankot ",  "jammu tawi",  "udhampur",  "shri mata vaishno devi katra"},
        
        {"20808 - Hirakud SF Express","amritsar", "beas", "jalandhar city", "ludhiana", "ambala cantonment", "panipat", "new delhi", "hazrat nizamuddin", "mathura", "agra cantonment", "gwalior", "datia", "virangana lakshmibai jhansi", "lalitpur", "bina malkhedi", "khurai", "saugor", "damoh", "katni murwara", "umaria", "shahdol", "burhar", "anuppur", "pendra road", "bilaspur", "akaltara", "champa", "sakti", "kharsia", "raigarh", "brajarajnagar", "jharsuguda road", "sambalpur", "rairakhol", "angul", "talcher", "dhenkanal", "bhubaneswar", "khurda road", "balugaon", "chatrapur", "brahmapur", "palasa", "srikakulam road", "vizianagram", "visakhapatnam"},
        
        
    };
    
    
    //ARRIVAL OF TERMINATING TRAINS      //ARRIVAL OF TERMINATING TRAINS      //ARRIVAL OF TERMINATING TRAINS
    std::vector<std::vector<std::string>> arrivalarrays = {
        
        {"19326 - Amritsar - Indore Bi-Weekly Express","First", "02:18", "02:55", "04:15", "05:05", "06:00", "06:43", "07:30", "08:08", "08:28", "09:12", "10:28", "11:10", "11:45", "13:08", "13:43", "13:55", "15:55", "17:48", "19:30", "20:13", "21:08", "22:08", "23:15", "23:56", "00:55"},
        
        {"19226", "02.53", "03.35", "04.18", "05.03", "05.12", "05.34", "07.00", "07.58", "08.19", "08.36", "09.35", "10.16", "10.44", "11.25", "11.51", "12.25", "14.38", "15.10", "16.15", "16.51", "17.43", "18.08", "19.50", "20.30"},
        
        {"19225", "01.33", "02.04", "02.23", "02.38", "03.30", "04.45", "06.20"},
        
        {"12204", "First", "04.28", "05.05", "05.28", "06.20", "08.00", "10.50", "12.17", "13.48", "15.11", "16.55", "18.30", "00.05", "02.05", "03.15", "04.27", "05.20", "06.15", "06.38", "07.35", "08.01", "08.38", "10.15", "11.20"},
        
        {"22126", "First", "04.28", "05.05", "06.03", "08.00", "10.50", "13.55", "15.50", "17.20", "21.15", "03.45"},
        
        {"12014", "First", "05.23", "05.58", "06.19", "06.57", "07.46", "08.32", "11.02"},
        
        {"12242", "First", "05.38", "06.13", "06.35", "07.12", "09.23", "09.40"},
        
        {"12716", "First", "05.58", "06.35", "07.00", "07.37", "08.30", "08.46", "09.02", "09.45", "10.20", "10.45","11.09", "12.45", "13.25", "14.31", "15.10", "16.10", "16.38", "17.06", "17.43", "18.37", "19.56","20.55", "22.30", "00.00", "02.42", "03.38", "04.40", "05.08", "05.39", "06.13", "07.30", "09.40","10.35", "11.44", "12.25", "13.13", "14.35"},
        
        {"12318", "First", "06.23", "07.02", "08.03", "09.09", "10.00", "11.20","13.04", "14.52", "16.20", "20.05", "22.11", "01.00", "02.15", "05.40","06.05", "07.04", "07.56", "09.00", "09.37", "10.04", "11.18", "14.45"},
    
        {"12358", "First", "06.23", "07.02", "08.03", "10.00", "11.20","14.52", "16.20", "20.05", "01.00", "02.10", "03.21", "04.35", "06.26","07.15", "08.23", "11.40"},
        
        {"12484","First", "06.23", "07.02", "08.03", "10.00", "12.55", "13.21", "18.05","21.30", "01.10", "03.00", "06.00", "07.35", "11.18", "13.20", "18.25","23.10", "01.05", "01.54", "03.07", "04.32", "06.20", "07.32", "09.30","10.47", "12.00", "12.42", "14.30"},
        
        {"14616", "First", "06.23", "07.02", "07.25", "08.20", "09.59", "10.39","10.55", "11.45", "12.30", "13.25", "14.14", "14.37", "15.17", "17.22","19.05", "19.53", "21.05"},
        
        {"12460","First", "06.43", "07.20", "07.34", "07.48", "08.08", "08.50", "09.32","09.54", "10.16", "10.40", "11.20", "11.45", "12.09", "12.39", "13.21","14.15"},
        
        {"14618","First", "07.03", "07.42", "08.05", "08.25", "09.15", "09.37", "10.22", "10.40", "11.22","12.08", "12.40", "13.56", "14.33", "15.16", "16.20", "16.55", "17.50", "20.01", "21.12","22.52", "00.05", "01.36", "03.05", "04.15", "04.45", "05.13", "05.35", "06.06", "07.25","08.11", "08.40", "08.55", "09.15", "09.30", "09.47", "10.03", "10.15", "10.27", "10.41","11.10", "11.46", "12.10", "13.15", "13.55", "14.37", "14.50", "15.40", "16.25", "16.51","17.35"},
        
        {"12054","First", "07.18", "07.57", "08.20", "09.15", "10.00", "10.55", "11.41", "12.13", "13.00", "13.50"},
        
        {"12926","First", "08.03", "08.40", "08.59", "09.13", "09.50", "11.46", "12.15", "13.00", "13.40", "14.06", "14.32","15.05", "15.38", "16.20", "17.01", "19.10", "19.48", "20.23", "20.48", "21.25", "22.08", "23.30", "00.38","01.38", "03.38", "04.25", "05.38", "06.04", "07.15", "08.15", "09.18", "10.24", "10.53", "11.30", "11.54","12.32", "13.55", "14.55"},
        
        {"15708","First", "08.39", "08.58", "09.36", "09.55", "10.09", "10.29", "10.50", "11.53", "12.10","12.26", "13.25", "14.29", "14.58", "15.23", "16.42", "17.20", "19.06", "19.38", "20.03","20.48", "21.18", "22.13", "00.25", "00.57", "02.10", "02.39", "03.21", "05.25", "05.52","06.42", "07.15", "08.15", "09.21", "10.03", "10.30", "12.05", "12.49", "13.15", "13.30","14.18", "14.52", "15.19", "15.40", "16.55", "17.21", "18.01", "18.16", "19.17", "19.43","20.20", "20.58", "22.10"},
        
        {"18101", "09.08", "09.28", "09.51", "10.03", "10.40", "12.31", "13.24", "14.25"},
        
        {"18309", "09.08", "09.28", "09.51", "10.03", "10.40", "12.31", "13.24", "14.25"},
        
        {"04654","First", "14.00", "17.30", "22.10", "03.55", "07.00", "09.30", "10.30", "14.25", "17.45"},
        
        {"11058","First", "09.04", "09.23", "09.42", "10.08", "10.24", "10.38", "10.58", "11.30", "12.21", "12.40", "13.25", "14.06", "14.40", "15.22","15.48", "16.10", "16.37", "16.55", "17.10", "17.18", "17.30", "17.46", "18.01", "18.17", "18.30", "18.45", "18.56", "19.09", "19.24", "19.50","20.25", "20.51", "21.12", "21.23", "21.53", "22.28", "23.00","23.50", "00.48", "01.23", "01.55", "02.36", "03.10", "04.05", "04.50", "05.24", "05.56", "06.19", "07.05","07.28", "07.50", "08.08", "08.29", "09.20", "09.37", "09.53", "10.08", "10.41", "10.52", "11.15", "11.53","12.16", "12.28", "12.55", "13.18", "13.43", "14.23", "14.58", "15.23", "15.41", "15.59", "16.35", "17.08","17.42", "18.18", "19.18", "20.17", "20.29", "22.47", "23.12", "23.37", "00.05"},
        
        {"22430","09.00", "09.53", "10.33", "11.38", "12.40", "13.40", "14.20", "14.45", "15.11", "15.44", "16.15", "16.55"},
        
        {"12408","First", "09.53", "10.33", "11.38", "13.32", "14.50", "18.10", "22.32", "04.45", "05.51", "06.50", "07.50", "09.10", "10.05", "11.12", "13.00", "15.15", "16.00", "18.35"},
        
        {"04652","First", "14.45", "17.40", "21.10", "02.30", "07.15", "12.25","14.45", "16.10", "17.30", "20.00"},
        
        {"18104","First", "13.13", "13.52", "14.53", "16.40", "17.28", "18.00", "18.58", "19.18", "21.22","22.50", "02.50", "05.10", "06.58", "09.30", "10.40", "11.30", "12.03", "12.20", "12.36","12.58", "14.10", "15.18", "16.22", "17.50", "18.58", "21.10"},
        
        {"22446", "First", "13.13", "13.52", "14.53", "16.40", "17.28", "18.00","18.58", "19.18", "21.22","22.50", "02.50", "05.10", "06.58", "09.30", "10.40", "11.30", "12.03", "12.20", "12.36","12.58", "14.10", "15.18", "16.22", "17.50", "18.58", "21.10"},
        
        {"22424","First", "13.13", "13.52", "14.16", "14.53", "16.40", "18.00", "21.22", "22.50", "00.05","02.05", "04.40", "05.18", "06.27", "06.53","07.55"},
        
        {"14650","First", "13.13", "13.53", "14.12", "14.28", "14.42", "15.22", "16.03", "16.40", "16.50", "17.03", "17.22", "17.45", "18.10","19.00", "19.45", "20.49", "21.13", "22.00", "23.10", "00.12", "00.58", "01.59", "03.07", "06.10", "07.06", "08.30", "08.51","09.38", "10.55", "11.39", "12.25", "12.49", "13.15", "13.35", "14.06", "14.45", "15.44", "16.40", "18.16", "19.30", "21.05","21.54", "22.08", "22.30", "23.08", "23.24", "23.36", "23.46", "00.30"},
        
        {"14674","First", "13.13", "13.53", "14.12", "14.28", "14.42", "15.22", "16.03", "16.40", "16.50", "17.03", "17.22", "17.45", "18.10","19.00", "19.45", "20.49", "21.13", "22.00", "23.10", "00.12", "00.58", "01.59", "03.07", "06.10", "07.06", "08.30", "08.51","09.38", "10.55", "11.39", "12.25", "12.49", "13.15", "13.35", "14.06", "14.45", "15.44", "16.40", "18.16", "19.30", "21.05","21.54", "22.08", "22.30", "23.08", "23.24", "23.36", "23.46", "00.30"},
        
        {"19612","First", "13.53", "14.30", "14.53", "15.30", "16.25", "16.55", "17.18", "18.25", "19.41", "19.58", "20.15", "21.05", "22.18", "22.49","00.10", "01.15", "02.50", "03.35", "03.59", "04.27", "04.41", "04.58", "05.19", "05.54", "06.12", "06.25", "08.08", "09.05"},
        
        {"14604","First", "13.53", "14.30", "15.30", "16.29", "17.20", "18.30", "20.03", "20.35", "21.45", "23.10", "00.18", "02.05", "03.38", "04.40","05.18", "06.27", "06.53", "07.55", "08.58", "10.05", "11.50", "13.01", "13.15", "14.35", "16.15", "16.42", "16.57", "17.13","18.30", "18.45", "19.03", "19.17", "19.50"},
        
        {"12380", "First", "13.53", "14.30", "15.30", "17.15", "20.00", "01.10", "06.10", "07.21", "08.35", "11.37", "12.28", "12.50", "13.35", "14.33", "16.35"},
        
        {"14505","First", "14.28", "15.05", "16.00", "17.09", "17.58", "18.05", "18.15", "18.30", "18.51", "19.01", "19.30"},
        
        {"12422", "First", "14.58", "15.35", "15.58", "16.55", "18.13", "18.38", "19.40", "20.07", "21.10", "23.00", "01.20", "02.58", "04.30", "06.30", "08.30", "10.20", "13.05", "15.23", "16.15", "17.00", "18.09", "18.49", "20.35", "21.40"},
        
        {"12498","First", "15.38", "16.13", "16.36", "17.35", "18.08", "18.35", "19.15", "19.55", "20.20", "20.44", "21.20", "22.00", "22.30"},
        
        {"15934","First", "16.08", "16.45", "17.55", "20.18", "21.30", "00.47", "02.23","03.34", "06.35", "10.20", "11.46", "15.25", "17.00", "18.00", "20.10", "21.50","22.21", "23.45", "00.53", "03.30", "07.05", "09.12", "09.37", "11.50", "14.00","15.55", "17.36", "18.14", "18.30", "19.25", "20.02", "20.40", "23.00", "00.00","01.00", "03.00"},
            
        {"22429", "16.28", "16.50", "17.05", "17.17", "18.20"},
        
        {"18238","First", "16.24", "16.43", "17.23", "17.39", "17.53", "18.13", "18.35", "19.28", "19.36", "19.46", "19.56", "20.20", "20.30", "20.50", "21.12", "21.35", "22.23", "22.41", "22.49", "00.30", "01.05", "01.25", "01.43", "01.58", "02.11", "02.24", "02.42", "02.57", "03.20", "03.39", "04.10", "04.51", "05.18", "05.48", "06.00", "07.20", "08.00", "08.15", "09.43", "10.09", "10.40", "11.16", "11.42", "12.40", "13.11", "13.23", "13.40", "14.12", "15.50", "16.11", "16.32", "16.58", "17.55", "18.12", "18.33", "19.08", "20.20", "21.27", "22.02", "22.25", "22.43", "23.23", "23.39", "23.45", "02.10", "02.51", "03.25", "03.43", "04.10", "05.00", "05.17", "05.35", "06.10", "06.39", "07.25", "07.51", "08.25", "09.08", "09.30", "10.24", "10.55"},
        
        {"12030","First","17.18", "17.53", "18.14", "18.50", "19.52", "20.26", "22.50"},
        
        {"12032","First","17.18", "17.53", "18.14", "18.50", "19.52", "20.26", "22.50"},
        
        {"12412","First", "17.33", "18.06", "18.30", "19.07", "20.01", "20.36", "20.54", "21.08", "21.30"},
        
        {"19614","First", "18.13", "18.52", "19.15", "20.02", "20.48", "21.20", "21.48", "22.37", "23.55", "01.15", "02.50", "03.35", "03.59", "04.27", "04.41", "04.58", "05.19", "05.54", "06.04", "06.25", "08.08", "09.05"},
        
        {"15532","First", "18.13", "18.52", "20.02", "23.25", "00.20", "02.00", "03.02", "05.25", "06.51", "11.15", "14.00", "15.17", "16.50", "17.54", "18.22", "19.05", "20.20", "21.36", "21.50", "22.45", "23.45", "00.12", "00.28", "01.20", "01.41", "02.26", "03.05"},
        
        {"19416","18:13", "19:00", "22:25", "00:40", "02:15", "03:30", "04:25", "07:50", "08:35", "08:59", "09:47", "10:08", "10:47", "11:10", "12:02", "12:43", "13:25", "14:17", "15:23", "16:01", "16:18", "17:35", "18:48", "19:55", "21:10", "22:00"},
        
        {"14654","First", "18.33", "18.52", "19.15", "19.38", "19.58", "20.30", "21.20", "21.45", "22.13", "23.07", "00.45"},
        
        {"13006","First", "18.53", "19.13", "19.30", "19.47", "20.02", "20.40", "22.06","23.00", "23.45", "00.45", "01.37", "01.58", "02.36", "02.58", "03.16","04.53", "05.25", "06.21", "07.29", "08.24", "08.53", "10.35", "11.33","12.05", "12.34", "12.51", "13.06", "13.45", "14.23", "14.46", "15.21","16.50", "17.12", "17.55", "18.43", "18.58", "19.14", "19.32", "19.47","20.23", "21.00", "21.30", "21.55", "22.28", "23.00", "23.45", "01.23","02.00", "02.30", "03.12", "03.58", "04.17", "04.37", "05.45", "07.30"},
        
        {"12904","First", "19.23", "20.00", "21.00", "22.50", "23.33", "00.15", "01.05","01.28", "01.46", "02.00", "02.58", "03.45", "04.19", "05.48", "06.13","06.40", "07.03", "07.13", "07.45", "08.30", "10.10", "11.18", "11.38","12.03", "13.40", "14.15", "15.26", "15.52", "17.05", "18.01", "19.41","22.46", "23.35"},
        
        {"15212","First", "19.48", "20.27", "20.51", "21.11", "21.38", "22.00","22.48", "23.07", "00.05", "00.45", "01.40", "02.46", "03.26", "05.07","06.35", "07.43", "08.42", "09.35", "10.17", "12.10", "13.15", "14.33","16.25", "17.23", "17.45", "17.58", "18.13", "19.02", "19.26", "19.53","20.15", "20.30", "21.01", "21.36", "22.11", "22.23", "22.33", "22.47","00.05", "00.31", "00.58", "01.30", "02.28", "02.55"},
        
        {"18310","20.04", "20.23", "21.10", "21.27", "21.44", "22.36", "22.58", "01.35","02.30", "02.57", "03.15", "03.40", "04.38", "05.12", "05.51", "06.30","07.26", "08.48", "09.03", "10.10", "10.50", "11.48", "12.54", "14.20","15.28", "17.10", "17.57", "18.33", "18.47", "19.25", "21.00", "22.30","23.35", "00.00", "00.22", "00.35", "01.10", "01.40", "02.12", "02.41","03.16", "03.42", "04.13", "04.55", "05.50", "06.10", "07.10","08.30", "08.55", "10.04", "10.54", "11.34", "12.55","13.31", "15.05", "15.38", "16.15"},
        
        {"18102","20.04", "20.23", "21.10", "21.27", "21.44", "22.36", "22.58", "01.35", "02.30","02.57", "03.15", "03.40", "04.38", "05.12", "05.51", "06.30", "07.26", "08.48","10.10", "10.50", "11.48", "12.54", "14.20", "15.28", "17.10", "17.57", "18.33","18.47", "19.30", "21.03", "22.30", "23.35", "00.00", "00.22", "00.35", "01.10","01.40", "02.12", "02.41", "03.16", "03.42", "04.13","04.55", "05.50", "06.10","07.10", "08.48", "09.50"},
        
        {"14632","First", "21.54", "22.13", "22.50", "23.09", "23.22", "23.44", "00.06", "01.46", "02.35", "03.21", "04.00", "04.08", "04.45", "05.36", "06.05", "06.49", "06.57", "07.04", "07.25", "07.45", "08.09", "08.28", "08.55", "09.16", "09.45"},
        
        {"19415","00.19", "02.00", "04.10", "05.14", "06.15"},
        
        {"20808",  "First", "00:23", "01:08", "02:20", "04:20", "05:36", "05:58", "08:00", "08:26", "09:58","10:45", "12:32", "13:36", "14:15", "15:26", "16:58", "17:16", "18:00", "19:08", "21:15","22:42", "23:45", "00:06", "00:31", "01:27", "04:00", "04:37", "05:05", "05:27","05:42","06:15", "07:06", "07:20", "08:30", "09:52", "11:25", "12:05", "13:00", "14:20", "14:45","15:45", "16:22", "16:40", "18:23", "19:18", "20:15", "21:40"}};
    
    
    
    
    //DEPARTURE OF TERMINATING TRAINS   //DEPARTURE OF TERMINATING TRAINS    //DEPARTURE OF TERMINATING TRAINS
         std::vector<std::vector<std::string>> deparrays = {
             
        {"19326 - Amritsar - Indore Bi-Weekly Express","01:50", "02:20", "03:05", "04:25", "05:07", "06:05", "06:45", "07:40", "08:10", "08:30","09:17", "10:30", "11:25", "11:47", "13:10", "13:45", "14:00", "16:00", "17:50", "19:40", "20:15", "21:10", "22:10","23:17","23:58", "Last"},
        
        {"19226", "02.55", "04.00", "04.20", "05.05", "05.14", "05.36", "07.25", "08.00", "08.21", "08.38", "09.45", "10.18", "10.46", "11.30", "11.53", "12.30", "14.40", "15.20", "16.17", "16.56", "17.48", "18.10", "20.00", "Last"},
        
        {"19225", "01.35", "02.06", "02.25", "02.40", "03.55", "04.47", "Last"},
        
        {"12204","04.00", "04.30", "05.10", "05.30", "06.30", "08.10", "11.05", "12.19", "13.53", "15.13", "16.57", "18.40", "00.15", "02.10", "03.20", "04.32", "05.25", "06.20", "06.40", "07.45", "08.03", "08.40", "10.17", "Last"},
        
        {"22126","04.00", "04.30", "05.10", "06.13", "08.10", "11.15", "14.00", "15.52", "17.28", "21.25", "Last"},
        
        {"12014","04.55", "05.25", "06.01", "06.21", "07.02", "07.48", "08.33", "Last"},
        
        {"12242","05.10", "05.40", "06.17", "06.37", "07.17", "09.25", "Last"},
        
        {"12716","05.30", "06.00", "06.40", "07.02", "07.47", "08.32", "08.48", "09.04", "09.50", "10.22", "10.47","11.11", "13.00", "13.27", "14.33", "15.15", "16.12", "16.40", "17.08", "17.45", "18.45", "19.58","20.57", "22.35", "00.10", "02.45", "03.40", "04.45", "05.10", "05.40", "06.15", "07.40", "09.45","10.40", "11.45", "12.30", "13.15", "Last"},
             
        {"12318", "05.55", "06.25", "07.07", "08.13", "09.11", "10.05", "11.25", "13.06","15.00", "16.22", "20.15", "22.13", "01.10", "02.25", "05.50", "06.10","07.06", "08.00", "09.05", "09.39", "10.06", "11.28", "Last"},
        
        {"12358", "05.55", "06.25", "07.07", "08.13", "10.05", "11.25", "13.06", "16.22", "20.15", "01.10", "02.20", "03.23", "04.40", "06.28","07.20", "08.25", "Last"},
        
        {"12484", "05.55", "06.25", "07.07", "08.13", "10.20", "13.10", "13.23","18.15", "21.35", "01.18", "03.05", "06.05", "07.40", "11.20", "13.25","18.35", "23.12", "01.15", "01.55", "03.10", "04.35", "06.25", "07.35","09.35", "10.50", "12.02", "12.45", "Last"},
        
        {"14616", "05:55","06.25", "07.07", "07.27", "08.30", "10.01", "10.41", "11.00","11.50", "12.32", "13.32", "14.16", "14.42", "15.22", "17.30", "19.25","19.55", "Last"},
        
        {"12460","06.15", "06.45", "07.25", "07.36", "07.50", "08.10", "08.55", "09.34","09.56", "10.18", "10.50", "11.22", "11.47", "12.11", "12.41", "13.23", "Last"},
        
        {"14618","06.35", "07.05", "07.47", "08.07", "08.27", "09.25", "09.39", "10.24", "10.42", "11.30","12.10", "12.50", "13.58", "14.38", "15.18", "16.28", "16.57", "17.52", "20.03", "21.22","22.57", "00.15", "01.39", "03.15", "04.20", "04.50", "05.15", "05.40", "06.08", "07.35","08.13", "08.45", "09.00", "09.17", "09.32", "09.49", "10.05", "10.17", "10.29", "10.43","11.20", "11.48", "12.12", "13.20", "14.00", "14.39", "14.52", "16.05", "16.30", "16.53","Last"},
        
        {"12054","06.50", "07.20", "08.02", "08.22", "09.20", "10.02", "11.04", "11.43", "12.18", "13.02", "Last"},
        
        {"12926","07.35", "08.05", "08.50", "09.01", "09.15", "10.00", "11.48", "12.20", "13.10", "13.42", "14.08", "14.34","15.07", "15.40", "16.35", "17.03", "19.15", "19.50", "20.25", "20.50", "21.30", "22.10", "23.40", "00.40","01.40", "03.40", "04.35", "05.40", "06.06", "07.17", "08.25", "09.20", "10.29", "10.55", "11.32", "11.56","12.34", "13.58", "Last"},
        
        {"15708","08.25", "08.41", "09.00", "09.46", "09.57", "10.11", "10.31", "11.00", "11.55", "12.12","12.28", "13.40", "14.31", "15.00", "15.25", "16.44", "17.35", "19.08", "19.40", "20.05","20.50", "21.20", "22.18", "00.30", "00.59", "02.20", "02.42", "03.23", "05.30", "05.54","06.45", "07.17", "08.25", "09.23", "10.05", "10.40", "12.15", "12.51", "13.20", "13.35","14.28", "14.54", "15.21", "15.45", "17.05", "17.23", "18.03", "18.18", "19.19", "19.45","20.22", "21.00", "Last"},
        
        {"18101", "09.10", "09.30", "09.53", "10.05", "11.05", "12.33", "13.26", "Last"},
        
        {"18309", "09.10", "09.30", "09.53", "10.05", "11.05", "12.33", "13.26", "Last"},
        
        {"04654","08.40", "14.10", "17.40", "22.20", "04.05", "07.10", "09.35", "10.35", "14.35", "Last"},
        
        {"11058","08.50", "09.06", "09.25", "09.44", "10.15", "10.26", "10.40", "11.00", "11.45", "12.23", "12.45", "13.45", "14.08", "14.45", "15.25","15.50", "16.23", "16.39", "16.57", "17.12", "17.20", "17.32", "17.48", "18.03", "18.19", "18.32", "18.47", "18.58", "19.11", "19.26", "19.52","20.40", "20.53", "21.14", "21.25", "21.55", "22.30", "23.05" , "23.55", "00.50", "01.25", "01.57", "02.38", "03.12", "04.13", "04.52", "05.26", "05.58", "06.20", "07.10","07.30", "07.52", "08.10", "08.31", "09.25", "09.39", "09.55", "10.10", "10.42", "10.54", "11.25", "11.55","12.18", "12.30", "12.57", "13.20", "13.45", "14.25", "15.00", "15.25", "15.43", "16.00", "16.40", "17.10","17.44", "18.20", "19.20", "20.20", "20.30", "22.50", "23.15", "23.40", "Last"},
        
        {"22430", "09.55", "10.38", "11.48", "12.42", "13.50", "14.22", "14.47", "15.13", "15.46", "16.17", "Last"},
        
        {"12408","09.25", "09.55", "10.38", "11.48", "13.40", "15.05", "18.18", "22.42", "04.55", "05.53", "06.55", "07.55", "09.15", "10.10", "11.17", "13.05", "15.25", "16.02", "Last"},
        
        {"04652","10.55", "14.50", "18.10", "21.20", "02.40", "07.40", "12.40","14.50", "16.35", "17.35", "Last"},
        
        {"18104","12.45", "13.15", "13.58", "15.03", "16.50", "17.30", "18.10", "19.00", "19.20", "21.30","22.52", "03.00", "05.15", "07.00", "09.40", "10.50", "11.32", "12.05", "12.22", "12.38","13.00", "14.15", "15.20", "16.27", "17.55", "19.00", "Last"},
        
        {"22446","12.45", "13.15", "13.58", "15.03", "16.50", "17.30", "18.10", "19.00", "19.20", "21.30","22.52", "03.00", "05.15", "07.00", "09.40", "10.50", "11.32", "12.05", "12.22", "12.38","13.00", "14.15", "15.20", "16.27", "17.55", "19.00", "Last"},
        
        {"22424","12.45", "13.15", "13.58", "14.18", "15.03", "16.50", "18.10", "21.30", "22.52", "00.07","02.15", "04.50", "05.20", "06.30", "06.55", "Last"},
        
        {"14650","12.45", "13.15", "13.54", "14.19", "14.30", "14.44", "15.24", "16.13", "16.42", "16.52", "17.05", "17.24", "17.47", "18.18","19.05", "20.10", "20.54", "21.18", "22.05", "23.15", "00.20", "01.00", "02.01", "02.09", "06.20", "07.08", "08.35", "08.53","09.40", "11.20", "11.41", "12.30", "12.51", "13.20", "13.37", "14.08", "14.50", "15.46", "16.50", "18.21", "19.35", "21.30","21.56", "22.10", "22.40", "23.10", "23.26", "23.38", "23.48", "Last"},
        
        {"14674","12.45", "13.15", "13.54", "14.19", "14.30", "14.44", "15.24", "16.13", "16.42", "16.52", "17.05", "17.24", "17.47", "18.18","19.05", "20.10", "20.54", "21.18", "22.05", "23.15", "00.20", "01.00", "02.01", "02.09", "06.20", "07.08", "08.35", "08.53","09.40", "11.20", "11.41", "12.30", "12.51", "13.20", "13.37", "14.08", "14.50", "15.46", "16.50", "18.21", "19.35", "21.30","21.56", "22.10", "22.40", "23.10", "23.26", "23.38", "23.48", "Last"},
        
        {"14604","13.25", "13.55", "14.35", "15.38", "16.31", "17.25", "18.35", "20.05", "20.37", "21.50", "23.12", "00.20", "02.15", "03.40", "04.50","05.20", "06.30", "06.55", "08.05", "09.00", "10.10", "12.00", "13.03", "13.20", "14.40", "16.20", "16.44", "16.59", "17.15","18.35", "18.50", "19.05", "19.19", "Last"},
        
        {"19612","13.25", "13.55", "14.35", "14.55", "15.40", "16.27", "17.00", "17.20", "18.50", "19.43", "20.00", "20.17", "21.40", "22.20", "22.52","00.15", "01.20", "02.55", "03.37", "04.02", "04.29", "04.43", "05.00", "05.21", "05.56", "06.15", "06.35", "08.10", "Last"},
        
        {"12380","13.25", "13.55", "14.35", "15.38", "17.25", "20.15", "01.15", "06.20", "07.23", "08.40", "11.42", "12.29", "13.00", "13.37", "14.35", "Last"},
        
        {"14505", "14.00", "14.30", "15.10", "16.08", "17.11", "18.00", "18.07", "18.17", "18.32", "18.53", "19.03", "Last"},
        
        {"12422","14.30", "15.00", "15.10", "16.00", "17.05", "18.25", "18.40", "19.42", "20.09", "21.12", "23.15", "01.25", "03.00", "04.38", "06.35", "08.40", "10.25", "13.10", "15.25", "16.16", "17.10", "18.10", "18.50", "20.40", "Last"},
        
        {"12498","15.10", "15.40", "16.18", "16.38", "17.40", "18.10", "18.37", "19.25", "19.57", "20.22", "20.46", "21.22", "22.02", "Last"},
        
        {"15934","15.40", "16.10", "16.55", "18.05", "20.25", "21.40", "00.55", "02.25","03.36", "06.45", "10.25", "11.48", "15.40", "17.05", "18.05", "20.20", "21.55","22.23", "23.55", "00.55", "03.40", "07.15", "09.17", "09.42", "12.00", "14.10","16.10", "17.38", "18.16", "18.32", "19.30", "20.04", "20.50", "23.02", "00.10","01.02", "Last"},
             
        {"22429","16.30", "16.52", "17.07", "17.19", "Last"},
        
        {"18238", "16.10", "16.26", "16.45", "17.30", "17.41", "17.55", "18.15", "18.43", "19.30", "19.38", "19.48", "19.58", "20.22", "20.32", "20.52", "21.14", "21.40", "22.25", "22.43", "22.51", "00.35", "01.07", "01.27", "01.45", "02.00", "02.13", "02.29", "02.44", "02.59", "03.22", "03.41", "04.25", "04.53", "05.20", "05.50", "06.01", "07.25", "08.02", "08.20", "09.45", "10.11", "10.42", "11.18", "11.44", "12.48", "13.12", "13.24", "13.42", "14.14", "15.55", "16.13", "16.34", "17.00", "18.00", "18.14", "18.35", "19.10", "20.30", "21.28", "22.04", "22.27", "22.44", "23.25", "23.40", "23.55", "02.25", "02.53", "03.27", "03.45", "04.12", "05.05", "05.19", "05.37", "06.15", "06.44", "07.35", "07.53", "08.35", "09.10", "09.32", "10.26","Last"},
        
        {"12030","16.50", "17.20", "17.56", "18.16", "18.55", "19.54", "20.30", "Last"},
             
        {"12032","16.50", "17.20", "17.56", "18.16", "18.55", "19.54", "20.30", "Last"},
        
        {"12412","17.05", "17.35", "18.09", "18.32", "19.12", "20.03", "20.38", "20.56", "21.10", "Last"},
        
        {"19614","17.45", "18.15", "18.57", "19.17", "20.12", "20.50", "21.35", "21.50", "22.40", "00.15", "01.20", "02.55", "03.37", "04.02", "04.29", "04.43", "05.00", "05.21", "05.56", "06.07", "06.35", "08.10", "Last"},
        
        {"15532","17.45", "18.15", "18.57", "20.20", "23.35", "00.25", "02.05", "03.04", "05.33", "06.53", "11.25", "14.10", "15.20", "17.00", "17.56", "18.27", "19.10", "20.30", "21.38", "21.55", "22.50", "23.50", "00.14", "00.30", "01.25", "01.43", "02.28", "Last"},
        
        {"19416","18:15", "19:25", "22:50", "01:05", "02:20", "03:35", "04:30", "07:55", "08:37", "09:02", "09:49", "10:10", "10:49", "11:20", "12:04", "12:45", "13:35", "14:19", "15:25", "16:03", "16:20", "17:45", "18:50", "19:57", "21:12", "Last"},
        
        {"14654","18.05", "18.35", "18.54", "19.20", "19.40", "20.00", "20.40", "21.22", "21.50", "22.15", "23.10", "Last"},
        
        {"13006","18.25", "18.55", "19.14", "19.38", "19.50", "20.04", "20.50", "22.08","23.10", "23.50", "00.55", "01.39", "02.00", "02.38", "03.00", "03.18","04.58", "05.27", "06.23", "07.31", "08.26", "08.55", "10.40", "11.34","12.10", "12.35", "12.53", "13.08", "13.50", "14.25", "14.48", "15.23","17.00", "17.13", "18.05", "18.45", "19.00", "19.16", "19.34", "19.49","20.25", "21.02", "21.40", "22.00", "22.30", "23.05", "23.47", "01.28","02.05", "02.34", "03.14", "04.03", "04.19", "04.39", "05.49", "Last"},
        
        {"12904","18.55", "19.25", "20.10", "21.10", "22.55", "23.35", "00.20", "01.07","01.30", "01.48", "02.05", "03.00", "04.00", "04.21", "05.50", "06.15","06.42", "07.05", "07.15", "07.50", "08.35", "10.20", "11.20", "11.40", "12.05", "13.42", "14.25", "15.28", "15.54", "17.07", "18.11", "19.46","22.48", "Last"},
        
        {"15212","19.20", "19.50", "20.33", "20.53", "21.13", "21.48", "22.02", "22.50","23.09", "00.10", "00.50", "01.50", "02.48", "03.28", "05.15", "06.37","07.45", "08.44", "09.40", "10.27", "12.15", "13.25", "14.36", "16.35","17.28", "17.47", "18.00", "18.15", "19.05", "19.28", "19.58", "20.17","20.33", "21.03", "21.39", "22.13", "22.25", "22.35", "22.49", "00.10","00.33", "01.00", "01.55", "02.31", "Last"},
        
        {"18310", "20.06", "20.25", "21.20", "21.30", "21.46", "22.38", "23.08", "01.45","02.40", "02.59", "03.17", "03.42", "04.40", "05.14", "05.53", "06.50","07.28", "08.50", "09.05", "10.15", "10.52", "11.50", "12.55", "14.25","15.30", "17.20", "17.58", "18.35", "18.49", "19.30", "21.02", "22.40","23.37", "00.02", "00.24", "00.37", "01.12", "01.45", "02.14", "02.46","03.18", "03.44", "04.15", "05.00", "06.00", "06.15", "07.15","08:40", "09.05","10.05", "10.55", "11.36", "13.05", "13.32", "15.10", "15.40", "Last"},
        
        {"18102","20.06", "20.25", "21.20", "21.30", "21.46", "22.38", "23.08", "01.45", "02.40","02.59", "03.17", "03.42", "04.40", "05.14", "05.53", "06.50", "07.28", "08.50","10.15", "10.52", "11.50", "12.55", "14.25","15.30","17.20", "17.58", "18.35","18.49", "19.35", "21.05", "22.40", "23.37", "00.02", "00.24", "00.37", "01.12","01.45","02.14", "02.46", "03.18", "03.44", "04.15", "05.00", "06.00", "06.15","07.15", "08.50", "Last"},
        
        {"14632","21.40", "21.56", "22.15", "23.00", "23.11", "23.25", "23.46", "00.16", "01.48", "02.43", "03.26", "04.02", "04.10", "04.55", "06.30", "06.50", "06.50", "06.58", "07.06", "07.35", "07.47", "08.11", "08.30", "08.57", "09.18", "Last"},
        
        {"19415","00.21", "02.25", "04.20", "05.16", "Last"},
        
        {"20808","23:55", "00:25", "01:18", "02:30", "04:25", "05:38", "06:00", "08:15", "08:28", "10:00","10:50", "12:34", "13:38", "14:23", "15:28", "17:00", "17:18", "18:05", "19:10", "21:25","22:44", "23:50", "00:08", "00:36", "01:29", "04:15", "04:39", "05:07", "05:29", "05:44","06:20", "07:08", "07:25", "08:50", "08:50", "09:54", "09:54", "11:27", "12:25", "12:25","12:25", "15:00", "15:00", "15:00", "15:00", "20:20", "Last"}
    };
    
    
    
    
    
    
    
    
    
    
    
    
    std::vector<std::vector<std::string>> rarrays = {
        
        {"19225 - Bhagat ki Kothi - Jammu Tawi Express","bhagat ki kothi", "jodhpur", "gotan", "merta road", "nagaur", "nokha", "bikaner", "lalgarh", "suratgarh", "pili bangan", "hanumangarh", "sangaria", "mandi dabwali", "bhatinda", "gangsar jaitu", "kot kapura", "faridkot", "firozpur cant", "makhu", "lohian khas", "sultanpur lodi", "kapurthala", "jalandhar city", "beas", "amritsar"},
        
        {"19226 - JammuTawi - Bhagat ki Kothi Express","jammu tawi", "hira nagar", "pathankot", "gurdaspur", "dhariwal", "batala", "verka", "amritsar"},
        
        {"14615 - Lal Kuan - Amritsar Express ", "lal kuan", "bazpur", "kashipur", "moradabad", "najibabad", "laksar", "roorkee", "saharanpur", "yamunanagar jagadhri", "ambala cant", "chandigarh", "mohali", "new morinda", "dhandari kalan", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"12459 - New Delhi - Amritsar Intercity Express" ,"new delhi", "subzi mandi", "sonipat", "panipat", "karnal", "kurukshetra", "ambala cant", "ambala city", "rajpura", "sirhind", "dhandari kalan", "phillaur", "phagwara", "jalandhar cant", "jalandhar city", "beas", "amritsar", "12460 - Amritsar - New Delhi InterCity Express"},
        
        {"14617 - Banmankhi - Amritsar Jan Sewa Express (UnReserved)", "banmankhi", "murliganj", "dauram madhepura", "saharsa", "s bhakhtiyarpur", "koparia", "mansi", "khagaria", "lakhminia", "begu sarai", "barauni", "bachwara", "vidyapatidham", "mohiuddinnagar", "shahpur patoree", "mehnar road", "desari", "akshaywat rai nagar", "hajipur", "sonpur", "dighwara", "chhapra", "ekma", "siwan", "mairwa", "bhatni", "deoria sadar", "gorakhpur", "basti", "gonda", "burhwal", "sitapur", "maikalganj", "bareilly", "rampur", "moradabad", "seohara", "najibabad", "laksar", "saharanpur", "yamunanagar jagadhri", "ambala cant", "rajpura", "sirhind", "dhandari kalan", "ludhiana", "phillaur", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"12053 - Haridwar - Amritsar Jan Shatabdi Express", "haridwar", "roorkee", "saharanpur", "yamunanagar jagadhri", "ambala cant", "sirhind", "dhandari kalan", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"12925 - Paschim SF Express ","mumbai", "borivali", "dahanu road", "vapi", "valsad", "navsari", "surat", "bharuch", "vadodara", "godhra", "dahod", "meghnagar", "ratlam", "nagda", "shamgarh", "ramganj mandi", "kota", "sawai madhopur", "gangapur city", "hindaun city", "bayana", "bharatpur", "mathura", "faridabad","hazrat nizamuddin", "new delhi", "subzi mandi", "sonipat", "panipat", "karnal", "kurukshetra", "ambala cant", "chandigarh", "mohali", "ludhiana", "phagwara", "jalandhar cant", "jalandhar city", "beas", "amritsar"},
        
        {"15707 - Amrapali Express ","katihar", "karagola road", "kursela", "naugachia", "thana bihpur", "mansi", "khagaria", "begu sarai", "barauni", "samastipur", "khudiram bose pusa", "dholi", "muzaffarpur", "hajipur", "sonpur", "dighwara", "chhapra", "siwan", "mairwa", "deoria sadar", "gorakhpur", "khalilabad", "basti", "mankapur", "gonda", "barabanki", "badshahnagar", "aishbagh", "unnao", "kanpur", "etawah", "firozabad", "tundla", "hathras", "aligarh", "khurja", "delhi", "subzi mandi", "sonipat", "panipat", "karnal", "ambala cant", "rajpura", "sirhind", "khanna", "ludhiana", "phillaur", "phagwara", "jalandhar cant", "jalandhar city", "beas", "jandiala", "amritsar"},
        
        {"04653 - New Jalpaiguri - Amritsar Clone SF Special ","new jalpaiguri", "katihar", "samastipur", "muzaffarpur", "chhapra", "gorakhpur", "sitapur", "moradabad", "saharanpur", "amritsar"},
        
        {"11057 - Mumbai CSMT - Amritsar Express ","csmt", "dadar", "thane", "kalyan","kasara", "devlali", "nasik road", "manmad", "chalisgaon", "pachora", "jalgaon", "bhusaval", "savda", "raver", "burhanpur", "nepanagar", "khandwa", "talvadya", "chhanera", "khirkiya", "harda", "timarni", "banapura", "itarsi", "narmadapuram", "budni", "obaidulla ganj", "mandi dip", "rani kamlapati", "bhopal", "vidisha", "gulabganj", "ganj basoda", "mandi bamora", "bina", "dhaura", "lalitpur", "talbahat", "babina", "virangana lakshmibai jhansi", "datia", "dabra", "gwalior", "morena", "dhaulpur", "agra cant", "mathura", "kosi kalan", "palwal", "faridabad", "hazrat nizamuddin", "new delhi", "subzi mandi",  "narela", "sonipat", "ganaur", "samalkha", "panipat",  "karnal",  "nilokheri", "kurukshetra", "shahabad markanda", "ambala cant", "ambala city", "rajpura", "patiala", "nabha", "dhuri", "malerkotla", "ahmedgarh", "ludhiana", "phillaur", "phagwara", "jalandhar cant", "jalandhar city", "beas", "jandiala", "amritsar"},
        
        {"12407 - New Jalpaiguri - Amritsar Karmabhoomi Express (UnReserved)","new jalpaiguri", "barsoi", "katihar", "khagaria", "samastipur", "muzaffarpur", "hajipur", "chhapra", "siwan", "deoria sadar", "gorakhpur", "sitapur", "moradabad", "saharanpur", "ambala cant", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"04651 - Jaynagar - Amritsar Clone Special","jaynagar", "darbhanga", "samastipur", "muzaffarpur", "chhapra", "shahganj", "lucknow", "moradabad", "delhi", "ambala cant", "amritsar"},
        
        {"18103 - Tatanagar - Amritsar Jallianwala Bagh Express","tatanagar", "purulia", "bokaro stl city", "gomoh", "koderma", "gaya", "rafiganj", "anugrah narayan road", "dehri on son", "sasaram", "bhabua road", "dd upadhyaya", "varanasi", "shahganj", "ayodhya cantt", "lucknow", "bareilly", "moradabad", "laksar", "roorkee", "saharanpur", "yamunanagar jagadhri", "ambala cant", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"22445 - Kanpur Central - Amritsar Weekly SF Express", "kanpur", "unnao", "bareilly", "moradabad", "laksar", "roorkee", "saharanpur", "ambala cant", "rajpura", "ludhiana", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"22423 - Gorakhpur - Amritsar Jansadharan SF Express (UnReserved)","gorakhpur", "khalilabad", "basti", "mankapur", "gonda", "sitapur", "shahjehanpur", "bareilly", "moradabad", "saharanpur", "ambala cant", "ludhiana", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"14673 - Shaheed Express ","jaynagar", "khajauli", "rajnagar", "madhubani", "sakri", "darbhanga", "laheria sarai", "haiaghat", "samastipur", "muzaffarpur", "hajipur", "chhapra", "suraimanpur", "ballia", "rasra", "indara", "mau", "muhammadabad", "azamgarh", "khorason road", "shahganj", "akbarpur", "ayodhya", "ayodhya cantt", "barabanki", "lucknow", "shahjehanpur", "bareilly", "rampur", "moradabad", "kanth", "najibabad", "laksar", "roorkee", "saharanpur", "yamunanagar jagadhri", "ambala cant", "ambala city", "rajpura", "sirhind", "mandi gobind garh", "khanna", "ludhiana", "phillaur", "phagwara", "jalandhar cant", "jalandhar city", "beas", "amritsar"},
        
        {"14649 - Saryu Yamuna Express","jaynagar", "khajauli", "rajnagar", "madhubani", "sakri", "darbhanga", "laheria sarai", "haiaghat", "samastipur", "muzaffarpur", "hajipur", "chhapra", "suraimanpur", "ballia", "rasra", "indara", "mau", "muhammadabad", "azamgarh", "khorason road", "shahganj", "akbarpur", "ayodhya", "ayodhya cantt", "barabanki", "lucknow", "shahjehanpur", "bareilly", "rampur", "moradabad", "kanth", "najibabad", "laksar", "roorkee", "saharanpur", "yamunanagar jagadhri", "ambala cant", "ambala city", "rajpura", "sirhind", "mandi gobind garh", "khanna", "ludhiana", "phillaur", "phagwara", "jalandhar cant", "jalandhar city",  "beas", "amritsar"},
        
        {"19611 - Ajmer - Amritsar Express (via Firozpur)","ajmer", "kishangarh", "jaipur", "gandhinagar jaipur", "getor jagatpura", "dausa", "bandikui", "baswa", "rajgarh", "alwar", "khairthal", "rewari", "bhiwani", "hisar", "sirsa", "kalanwali", "bhatinda", "gangsar jaitu", "kot kapura", "faridkot", "firozpur cant", "talwandi", "moga", "jagraon", "ludhiana", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"14603 - Saharsa - Amritsar Jansadharan Express (Via Sirhind) (UnReserved)","saharsa", "s bhakhtiyarpur", "dhamara ghat", "mansi", "khagaria", "salauna", "hasanpur road", "rusera ghat", "samastipur", "muzaffarpur", "hajipur", "sonpur", "chhapra", "siwan", "deoria sadar", "gorakhpur", "khalilabad", "basti", "mankapur", "gonda", "burhwal", "sitapur", "shahjehanpur", "bareilly", "moradabad", "dhampur", "najibabad", "saharanpur", "ambala cant", "sirhind", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"12379 - Sealdah - Amritsar Jallianwala Bagh Express","sealdah", "barddhaman", "durgapur", "asansol", "kumardubi", "dhanbad", "gaya", "sasaram", "dd upadhyaya", "kanpur", "delhi", "ambala cant", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"14506 - Nangal Dam - Amritsar Express","nangal dam", "anandpur sahib", "kiratpur sahib", "roop nagar", "kurali", "morinda", "new morinda", "samrala", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"12421 - Hazur Sahib Nanded - Amritsar SF Express","hazur sahib nanded", "purna", "hingoli deccan", "washim", "akola", "shegaon", "malkapur", "khandwa", "itarsi", "bhopal", "bina", "virangana lakshmibai jhansi", "gwalior", "agra cant", "new delhi", "rohtak", "narwana", "jakhal", "sangrur", "dhuri", "ludhiana", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"15933 - New Tinsukia - Amritsar Express ","new tinsukia", "simaluguri", "mariani", "furkating", "dimapur", "diphu", "lumding", "lanka", "hojai", "chaparmukh", "guwahati", "rangia", "new bongaigaon", "new alipurduar", "new cooch behar", "new jalpaiguri", "katihar", "khagaria", "barauni", "desari", "hajipur", "chhapra", "ballia", "ghazipur city", "varanasi", "akbarpur", "ayodhya cantt", "lucknow", "shahjehanpur", "bareilly", "moradabad", "saharanpur", "ambala cant", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"18237 - Chhattisgarh Express ","korba", "urga", "saragbundia", "madwarani", "kothari road", "balpur", "champa", "janjgir naila", "akaltara", "jairamnagar","bilaspur", "chakarbhatha", "belha", "bhatapara", "tilda", "raipur", "bhilai power house", "durg", "raj nandgaon", "dongargarh", "salekasa", "amgaon", "gondia", "tirora", "tumsar road", "bhandara road", "kamptee", "nagpur","narkher", "pandhurna", "multai", "amla", "betul", "ghoradongri", "itarsi", "narmadapuram", "obaidulla ganj", "rani kamlapati", "bhopal", "vidisha", "ganj basoda", "mandi bamora", "bina", "lalitpur", "talbahat", "basai", "babina", "virangana lakshmibai jhansi", "datia", "dabra", "gwalior", "morena", "dhaulpur", "agra cant", "raja ki mandi", "mathura", "chata", "kosi kalan", "palwal", "ballabgarh", "hazrat nizamuddin", "sahibabad", "ghaziabad", "guldhar", "modinagar", "meerut city", "meerut cant", "daurala", "khatauli", "muzaffarnagar", "deoband", "saharanpur", "yamunanagar jagadhri", "jagadhri workshop", "barara", "ambala cant", "ambala city", "rajpura", "sirhind", "mandi gobind garh", "khanna",  "ludhiana", "phillaur", "phagwara", "jalandhar cant", "jalandhar city", "beas", "jandiala", "amritsar"},
        
        {"12031 - New Delhi - Amritsar Shatabdi Express","new delhi", "ambala cant", "rajpura", "ludhiana", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"12029 - New Delhi - Amritsar Shatabdi Express","new delhi", "ambala cant", "rajpura", "ludhiana", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"12411 - Chandigarh - Amritsar Intercity Express","chandigarh", "mohali", "kharar", "new morinda", "samrala", "ludhiana", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"19613 - Ajmer - Amritsar Express (via Dhuri) ","ajmer", "kishangarh", "jaipur", "gandhinagar jaipur", "getor jagatpura", "dausa", "bandikui", "baswa", "rajgarh", "alwar", "khairthal", "rewari", "bhiwani", "hisar", "jakhal", "sangrur", "dhuri", "malerkotla", "ludhiana", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"15531 - Saharsa - Amritsar Jansadharan Express (Via Chandigarh) (UnReserved)" ,"saharsa", "s bhakhtiyarpur", "mansi", "khagaria", "hasanpur road", "rusera ghat", "samastipur", "muzaffarpur", "hajipur", "sonpur", "chhapra", "siwan", "bhatni", "deoria sadar", "gorakhpur", "basti", "gonda", "sitapur", "bareilly", "moradabad", "laksar", "saharanpur", "ambala cant", "chandigarh", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"14653 - Hisar - Amritsar Express","hisar", "jakhal", "sangrur", "dhuri", "malerkotla","ahmedgarh" ,"ludhiana", "phillaur", "phagwara", "jalandhar city", "kartarpur", "beas", "amritsar"},
        
        {"13005 - Howrah - Amritsar Mail","howrah", "barddhaman", "durgapur", "raniganj", "asansol", "chittaranjan", "madhupur", "jasidih", "jhajha", "kiul", "mokameh", "bakhtiyarpur", "patna saheb", "patna", "danapur", "ara", "dumraon", "buxar", "gahmar", "dildarnagar", "zamania", "dd upadhyaya", "kashi", "varanasi", "bhadohi", "janghai", "badshahpur", "partapgarh", "amethi", "gauriganj", "jais", "rae bareli", "bachhrawn", "lucknow", "balamau", "hardoi", "shahjehanpur", "bareilly", "rampur", "moradabad", "dhampur", "nagina", "najibabad", "laksar", "roorkee", "saharanpur", "yamunanagar jagadhri", "ambala cant", "rajpura", "ludhiana", "phillaur", "phagwara", "jalandhar cant", "jalandhar city", "kartarpur", "beas", "amritsar"},
        
        {"12903 - Golden Temple Mail ","mumbai", "borivali", "surat", "vadodara", "godhra", "dahod", "meghnagar", "ratlam", "nagda", "shamgarh", "bhawani mandi", "ramganj mandi", "kota", "sawai madhopur", "gangapur city", "shrimahaveerji", "hindaun city", "bayana", "bharatpur", "mathura", "faridabad", "hazrat nizamuddin", "ghaziabad", "meerut city", "meerut cant", "sakhoti tanda", "muzaffarnagar", "saharanpur", "yamunanagar jagadhri", "ambala cant", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"15211 - Jan Nayak Express (UnReserved)","darbhanga", "laheria sarai", "samastipur", "karpoorigram", "dholi", "muzaffarpur", "motipur", "mehsi", "chakia", "pipra", "bapudm motihari", "sagauli", "bettiah", "chanpatia", "narkatiaganj", "harinagar", "bagaha",  "kaptanganj", "gorakhpur", "basti", "gonda", "burhwal", "sitapur", "sitapur city", "maikalganj", "shahjehanpur", "bareilly", "moradabad", "najibabad", "laksar", "saharanpur", "yamunanagar jagadhri", "ambala cant", "rajpura", "sirhind", "dhandari kalan", "ludhiana", "phillaur", "phagwara","jalandhar cant", "jalandhar city", "beas", "amritsar"},
        
        {"14631 - Dehradun - Amritsar Express","dehradun", "raiwala", "motichur", "haridwar", "jwalapur", "ikkar h", "pathri", "laksar", "roorkee", "saharanpur", "yamunanagar jagadhri", "jagadhri workshop", "ambala cant", "chandigarh", "new morinda", "ludhiana", "phillaur", "phagwara", "jalandhar cant", "jalandhar city", "beas", "jandiala", "amritsar"},
        
        {"20807 - Hirakud SF Express","visakhapatnam", "vizianagram", "srikakulam road", "palasa", "brahmapur", "chatrapur", "balugaon", "khurda road", "bhubaneswar", "dhenkanal", "talcher", "angul", "rairakhol", "sambalpur", "jharsuguda road", "brajarajnagar", "raigarh", "kharsia", "sakti", "champa", "akaltara", "bilaspur", "pendra road", "anuppur", "burhar", "shahdol", "umaria", "katni murwara", "damoh", "saugor", "khurai", "bina malkhedi", "lalitpur", "virangana lakshmibai jhansi", "datia", "gwalior", "agra cant", "mathura", "hazrat nizamuddin", "new delhi", "panipat", "ambala cantonment", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"12317 - Akal Takht Express" ,"kolkata", "asansol", "madhupur", "jasidih", "jhajha", "kiul", "mokameh", "patna saheb", "patna", "dd upadhyaya", "varanasi", "sultanpur", "lucknow", "bareilly", "moradabad", "najibabad", "saharanpur", "ambala cant", "sirhind", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"12357 - Durgiana Express","kolkata", "asansol", "dhanbad", "parasnath", "gaya", "sasaram", "dd upadhyaya", "varanasi", "lucknow", "bareilly", "moradabad", "saharanpur", "ambala cant", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"12483 - Kochuveli - Amritsar Weekly SF Express","kochuveli", "kollam", "kayankulam", "alleppey", "ernakulam", "thrisur", "shoranur", "kozhikkode", "kannur", "kasaragod", "mangalore", "udupi", "madgaon", "ratnagiri", "chiplun", "panvel", "vasai road", "surat", "vadodara", "ratlam", "kota", "hazrat nizamuddin", "new delhi", "ambala cant", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"12013 - New Delhi - Amritsar Shatabdi Express","new delhi", "ambala cant", "sirhind", "ludhiana", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"12241 - Chandigarh - Amritsar SF Express","chandigarh", "mohali", "ludhiana", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"22125 - Nagpur - Amritsar AC SF Express","nagpur", "bhopal", "virangana lakshmibai jhansi", "gwalior", "agra cant", "new delhi", "ambala cant", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"12715 - Sachkhand Express","hazur sahib nanded", "purna", "parbhani", "selu", "jalna", "aurangabad", "manmad", "chalisgaon", "pachora", "jalgaon", "bhusaval", "burhanpur", "khandwa", "itarsi", "bhopal", "bina", "lalitpur", "virangana lakshmibai jhansi", "dabra", "gwalior", "morena", "dhaulpur", "agra cant", "mathura", "faridabad","hazrat nizamuddin", "new delhi", "panipat", "karnal", "kurukshetra", "ambala cant", "rajpura", "sirhind", "khanna", "ludhiana", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"12203 - Saharsa - Amritsar Garib Rath Express","saharsa", "simri bakhtiyarpur", "khagaria", "begu sarai", "barauni", "dalsingh sarai", "samastipur", "muzaffarpur", "hajipur", "chhapra", "siwan", "gorakhpur", "lucknow nr", "hardoi", "bareilly", "moradabad", "hapur", "new delhi", "ambala cant", "dhandari kalan", "phagwara", "jalandhar city", "beas", "amritsar"},
        
        {"19325 - Indore - Amritsar Bi-weekly Express","indore", "dewas", "maksi", "shajapur", "biyavra rajgarh", "ruthiyai", "guna", "shivpuri", "gwalior", "agra cant", "mathura", "faridabad", "hazrat nizamuddin", "ghaziabad", "meerut city", "muzaffarnagar", "deoband", "saharanpur", "yamunanagar jagadhri", "ambala cant", "sirhind", "dhandari kalan", "jalandhar city", "beas", "amritsar"},
        
        {"18102 - Jammu Tawi - Tatanagar Express","jammu tawi", "vijaypur jammu", "hira nagar", "pathankot", "dinanagar", "gurdaspur", "dhariwal", "batala", "amritsar"},
        
        {"18310 - Jammu Tawi - Sambalpur Express","jammu tawi", "vijaypur jammu", "hira nagar", "pathankot", "dinanagar", "gurdaspur", "dhariwal", "batala", "amritsar"},
        
        {"22429 - Delhi - Pathankot SF Express","delhi","panipat", "karnal", "kurukshetra", "ambala cant", "sirhind", "ludhiana", "jalandhar city", "beas", "amritsar"},
        
        {"22430 - Pathankot - Delhi SF Express","pathankot", "dinanagar", "gurdaspur", "dhariwal", "batala", "amritsar"},
        
        {"19415 - Ahmedabad - Shri Mata Vaishno Devi Katra  Express","ahmedabad", "sabarmati bg", "mahesana", "palanpur", "abu road", "falna", "rani", "marwar", "beawar", "ajmer", "kishangarh", "phulera", "jaipur", "gandhinagar jaipur", "dausa", "bandikui", "alwar", "khairthal", "rewari", "bhiwani", "hisar", "sirsa", "bhatinda", "firozpur cant", "jalandhar city", "beas", "amritsar"},
        
        {"19416 - Shri Mata Vaishno Devi Katra - Ahmedabad Express","shri mata vaishno devi katra", "udhampur", "jammu tawi", "pathankot", "batala", "amritsar"},
        
        {"18309 - Sambalpur - Jammu Tawi Express","sambalpur", "rengali", "jharsuguda", "rajgangpur", "rourkela", "orga", "bano", "govindpur road", "hatia", "ranchi", "muri", "ramgarh cantt", "barka kana", "patratu", "khalari", "tori", "latehar", "barwadih", "daltonganj", "garwa road", "garhwa", "nagaruntari", "wyndhamganj", "dudhinagar", "renukut", "chopan", "sonbhadra", "chunar", "mirzapur", "vindhyachal", "meja road", "prayagraj", "fatehpur", "kanpur central", "jhinjhak", "etawah", "shikohabad", "tundla", "hathras", "aligarh", "ghaziabad", "delhi", "subzi mandi", "sonipat", "panipat", "karnal", "kurukshetra", "shahabad markanda", "ambala cant", "chandigarh", "ludhiana", "phillaur", "phagwara", "jalandhar cant", "jalandhar city", "beas", "amritsar"},
        
        {"18101 - Tatanagar - Jammu Tawi Express", "tatanagar", "chandil", "muri", "ramgarh cantt", "barka kana", "patratu", "khalari", "tori", "latehar", "barwadih", "daltonganj", "garwa road", "garhwa", "nagaruntari", "wyndhamganj", "dudhinagar", "renukut", "chopan", "sonbhadra", "chunar", "mirzapur", "vindhyachal", "meja road", "prayagraj", "fatehpur", "kanpur central", "jhinjhak", "etawah", "shikohabad", "tundla", "aligarh", "ghaziabad", "delhi", "subzi mandi", "sonipat", "panipat", "karnal", "kurukshetra", "shahabad markanda", "ambala cant", "chandigarh", "ludhiana", "phillaur", "phagwara", "jalandhar cant", "jalandhar city", "beas", "amritsar"},
       
        {"12497 - Shan-e-Punjab Express","new delhi", "sonipat", "panipat", "karnal", "kurukshetra", "ambala cant", "rajpura", "khanna", "ludhiana", "phagwara", "jalandhar city", "beas", "amritsar"},
        
    };
    
    
    
    std::vector<std::vector<std::string>> deprarrays = {
        
        {"19225","06.20", "06.45", "07.45", "08.08", "09.05", "10.11", "12.10", "12.24", "15.05", "15.30", "16.10", "16.29", "17.03", "18.30", "18.54", "19.23", "19.42", "20.45", "21.20", "21.43", "21.53", "22.40", "23.35", "00.09", "01:15"},
        
        {"19226","21.00", "21.50", "23.20", "00.03", "00.20", "01.04", "01.30","02.25"},
        
        {"18101","17.05", "18.03", "18.55", "20.00", "20.50", "21.09", "21.35", "22.00", "22.25", "23.03", "23.25", "00.21", "00.33", "01.02", "01.16", "01.38", "02.02", "04.50", "05.32", "07.40", "08.12", "08.28", "09.01", "09.50", "11.12", "13.10", "14.11", "15.20", "16.02", "16.50", "18.03", "20.20", "21.25", "21.41", "22.12", "22.48", "23.15", "23.40", "23.58", "02.10", "03.13", "05.16", "05.32", "06.00", "06.26", "06.48", "07.19", "08.25"},
        
        {"18309","11.00", "11.25", "12.05", "12.57", "13.35", "14.28", "15.05", "15.45","17.00", "17.30", "18.40", "20.05","20.50", "21.09", "21.35", "22.00", "22.25", "23.03", "23.25", "00.21","00.33", "01.02", "01.16", "01.38","02.02", "04.50", "05.32", "07.40", "08.12", "08.28", "09.01", "09.50","11.12", "13.10", "14.11", "15.20","16.02", "16.50", "17.27", "18.03", "20.20", "21.25", "21.41", "22.12","22.48", "23.15", "23.40", "23.58","02.10", "03.13", "05.16", "05.32", "06.00", "06.26", "06.48","07.19","08.25"},
        
        {"22430","07.00", "07.27", "07.39", "07.54", "08.13", "09.25"},
        
        {"22429","08.15", "09.20", "09.44", "10.09", "11.15", "11.52", "13.05", "14.03", "14.37", "15.45"},
        
        {"19416","10.45", "11.11", "12.32", "14.45", "15.50", "17.45"},
        
        {"18310","14.35", "14.55", "15.21", "16.57", "17.34", "17.52", "18.08", "18.28", "19.50"},
        
        {"18102","14.35", "14.55", "15.21", "16.57", "17.34", "17.52", "18.08", "18.28", "19.50"},
        
        {"19415", "20.20", "20.39", "21.37", "23.05", "00.10", "01.30", "01.45", "02.35", "03.42", "05.00", "05.30","06.12", "07.20", "07.39", "08.18", "08.50", "10.10", "10.32", "11.35", "12.45", "13.55", "15.25","17.20", "19.20", "21.50", "22.23", "23.45"},
        
        {"14615","23.45", "00.38", "01.25", "02.50", "04.50", "05.30", "05.56","07.05", "07.33", "08.48", "09.48", "10.00", "10.30", "12.21","12.52", "13.22", "13.55", "Last"},
        
        {"12459","13.50", "14.32", "15.02", "15.26", "16.06", "17.05", "17.17", "17.34","17.57", "19.10", "19.26", "19.46", "20.30", "21.03", "Last"},
        
        {"14617","06.30", "06.49", "07.13", "08.40", "08.58", "09.10", "10.05", "10.20","10.37", "10.58", "11.35", "12.00", "12.14", "12.26", "12.44", "12.52","13.04", "13.17", "13.40", "13.50", "14.28", "16.00", "16.42", "17.10","17.30", "18.05", "18.30", "20.20", "21.27", "23.00", "23.59", "02.08","03.03", "05.20", "06.18", "07.10", "07.52", "08.36", "09.18", "10.35","11.03", "12.05", "12.27", "12.48", "13.36", "14.01", "14.17", "14.37","15.11", "15.44", "Last"},
        
        {"12053","14.45", "15.28", "16.20", "16.48", "17.50", "18.33", "19.35","20.06", "20.45", "21.18", "Last"},
        
        {"12925","11.25", "11.58", "13.10", "13.43", "14.09", "14.47", "15.52","16.34", "17.40", "19.00", "19.52", "20.19", "21.45", "23.00","00.03", "00.44", "01.55", "03.10", "04.25", "04.55", "05.25","06.10", "07.35", "09.29", "10.01", "11.05", "11.21", "11.52","12.25", "12.51", "13.16", "14.30", "15.25", "15.37", "17.45","18.16", "18.35", "18.50", "19.23", "Last"},
        
        {"15707", "22.45", "23.08", "23.23", "23.40", "23.55", "00.35", "00.55","01.40", "02.40", "04.05", "04.20", "04.36", "05.25", "06.25","06.40", "07.08", "08.50", "09.50", "10.08", "10.50", "12.25","13.03", "13.31", "14.20", "15.15", "16.35", "17.31", "18.08","19.15", "19.55", "21.40", "22.35", "23.12", "23.54", "00.20","00.54", "02.05", "02.28", "03.20", "04.24", "04.57", "05.23","05.48", "06.55", "07.16", "07.37", "07.50", "08.50", "09.06","09.42", "10.40", "11.13", "Last"},
        
        {"04653", "07.00", "10.40", "14.10", "15.10", "17.35", "20.55", "02.50", "07.43", "10.52", "Last"},
        
        {"11057","23:30", "23:40", "00:05", "00:35", "01:31", "02:55", "03:10", "04:10", "05:05", "05:35","06:20", "06:55", "07:15", "07:30", "07:50", "08:15", "09:25", "09:43", "10:11", "10:46","11:15", "11:29", "11:53", "12:50", "13:10", "13:23", "14:13", "14:27", "15:05", "15:35","16:15", "16:35", "16:52", "17:24", "17:55", "18:23", "18:46", "19:16", "19:38", "20:28","20:54", "21:18", "21:56", "22:30", "23:15", "23:55", "01:00", "01:32", "02:32", "02:56","03:16", "03:55", "04:10", "04:30", "04:46", "04:59", "05:14", "05:28", "05:54", "06:07","06:23", "06:43", "07:58", "08:11", "08:40", "09:10", "09:41", "10:40", "11:00", "11:33","12:55", "13:11", "13:45", "14:04", "14:20", "14:53", "15:37", "Last"},
            
        {"12407", "08.15", "10.20", "11.55", "13.50", "15.25", "16.15", "17.10", "18.55", "19.45", "20.46", "22.05", "03.55", "08.48", "12.05", "13.25", "15.05", "16.02", "16.35", "Last"},
        
        {"04651","04.15", "05.30", "07.25", "08.25", "11.25", "17.20", "22.40", "04.05", "07.25", "10.15", "Last"},
        
        {"22445","17.50", "18.13", "23.07", "00.53", "02.44", "03.08", "04.02", "05.25", "05.46", "07.05", "07.36", "08.10", "08.43", "Last"},
        
        {"22423","10.45", "11.23", "11.51", "12.40", "13.30", "16.18", "18.15", "19.16", "21.00", "00.35", "02.16", "03.54", "04.31", "05.10", "05.43", "Last"},
        
        {"14673", "07.20", "07.34", "07.45", "07.57", "08.13", "09.03", "09.15", "09.29", "10.50", "11.13", "11.50", "12.45", "14.40", "15.35", "15.54", "16.10", "16.35", "17.00", "19.15", "19.55", "20.26", "20.51", "21.22", "22.05", "23.55", "00.55", "03.21", "04.22", "05.15", "06.13", "06.45", "07.49", "08.35", "09.17", "10.20", "10.48", "11.45", "11.58", "12.35", "12.58", "13.07", "13.17", "14.16", "14.32", "14.52", "15.11", "15.30", "16.04", "Last"},
            
        {"14649", "07.20", "07.34", "07.45", "07.57", "08.13", "09.03", "09.15", "09.29", "10.50", "11.13", "11.50", "12.45", "14.40", "15.35", "15.54", "16.10", "16.35", "17.00", "19.15", "19.55", "20.26", "20.51", "21.22", "22.05", "23.55", "00.55", "03.21", "04.22", "05.15", "06.13", "06.45", "07.49", "08.35", "09.17", "10.20", "10.48", "11.45", "11.58", "12.35", "12.58", "13.07", "13.17", "14.16", "14.32", "14.52", "15.11", "15.30", "16.04", "Last"},

        {"19611","18.00", "18.27", "20.05", "20.21", "20.31", "21.07", "21.33", "21.46", "22.00", "22.28", "22.53", "00.01", "01.20", "02.20", "02.20", "02.20", "06.03", "06.26", "06.42", "07.03", "08.25", "08.51", "09.27", "09.51", "11.30", "12.01", "12.35", "13.08", "Last"},
        
        {"14603","16.55", "17.13", "17.34", "18.20", "18.35", "18.57", "19.13", "19.28", "20.20", "21.20", "22.15", "22.25", "00.25", "01.20", "02.35", "04.20", "04.59", "05.29", "06.22", "07.05", "08.15", "11.20", "13.30", "14.27", "16.15", "17.07", "17.41", "20.30", "22.10", "22.47", "23.56", "00.55", "01.30", "Last"},
        
        {"12379","13.10", "14.41", "15.27", "16.07", "16.31", "17.15", "20.05", "21.08", "22.40", "03.10", "09.15", "11.55", "13.33", "14.35", "15.08", "Last"},
        
        {"14506","07.20", "07.36", "07.45", "08.10", "08.25", "08.40", "08.50", "09.25", "10.34", "11.40", "12.14", "Last"},
            
        {"12421","11.05", "11.50", "13.00", "13.50", "16.05", "16.30", "17.05", "20.20", "22.45", "00.30", "02.18", "04.09", "05.10", "06.50", "10.25", "11.50", "12.59", "13.45", "14.25", "14.50", "16.05", "16.36", "17.10", "17.42", "Last"},

        {"15933","10.20", "11.58", "12.44", "13.42", "14.50", "15.27", "16.15", "16.45", "17.01", "17.34", "19.30", "21.10", "23.25", "00.52", "01.20", "04.15", "09.00", "11.11", "12.50", "14.00", "15.05", "17.15", "18.40", "20.00", "22.30", "00.45", "02.10", "06.00", "08.34", "09.31", "11.10", "15.10", "16.40", "18.20", "19.20", "19.53", "Last"},
            
        {"18237", "11:33", "11:44", "11:52", "12:01", "12:08", "12:15", "12:35", "12:46", "13:00", "13:13",
            "14:15", "14:40", "15:03", "15:25", "16:15", "16:55", "17:30", "17:51", "18:16", "18:49",
            "19:04", "19:45", "20:10", "20:28", "20:44", "21:19", "22:20", "23:30", "23:45", "00:25",
            "00:42", "01:02", "01:38", "04:20", "04:35", "05:25", "05:53", "06:15", "06:52", "07:17",
            "07:48", "09:30", "10:11", "10:38", "10:51", "11:03", "12:00", "12:22", "13:00", "13:40",
            "14:07", "15:32", "16:10", "16:20", "17:10", "17:26", "17:38", "18:52", "19:12", "19:25",
            "20:05", "20:33", "20:46", "21:06", "21:17", "21:28", "21:40", "21:48", "22:13", "22:31",
            "22:51", "00:05", "00:34", "00:41", "00:59", "01:40", "01:52", "02:07", "02:28", "02:36",
            "02:45", "03:43", "03:59", "04:18", "04:35", "04:55", "05:28", "06:15", "Last"
        },
            
        {"12031","07.20", "09.43", "10.04", "11.11", "11.42", "12.08", "12.40", "Last"},
            
        {"12029","07.20", "09.43", "10.04", "11.11", "11.42", "12.08", "12.40", "Last"},

        {"12411","06.35", "06.47", "07.19", "07.38", "08.07", "09.03", "09.34", "10.05", "10.36", "Last"},
                
        {"19613","18.00", "18.27", "20.05", "20.21", "20.31", "21.07", "21.33", "21.46", "22.00", "22.28", "22.53", "00.01", "01.20", "03.05", "04.21", "05.03", "05.45", "06.03", "07.50", "08.22", "09.05", "09.38", "Last"},
                
        {"15531","03.15", "03.33", "04.08", "04.25", "05.04", "05.22", "06.20", "07.20", "08.15", "08.25", "10.25", "11.20", "12.05", "12.35", "14.40", "15.46", "17.15", "20.20", "00.02", "01.48", "03.46", "05.10", "06.35", "07.33", "09.59", "11.20", "12.27", "Last"},
                
        {"13005","19.15", "20.22", "21.12", "21.30", "21.56", "22.19", "23.04", "23.33", "00.55", "01.35", "02.04", "02.35", "03.05", "03.50", "04.05", "04.37", "05.06", "05.30", "05.45", "06.07", "06.18", "08.15", "09.00", "09.25", "10.05", "10.35", "10.59", "11.40", "12.20", "12.34", "12.51", "13.25", "13.55", "15.50", "17.12", "17.41", "19.00", "20.05", "21.00", "22.00", "22.54", "23.12", "23.32", "00.15", "00.38", "01.45", "02.13", "03.20", "03.42", "05.45", "06.01", "06.29", "06.51", "07.12", "07.27", "07.45", "Last"},
        
        {"14653","00:05", "01:25", "02:33", "03:00", "03:13", "03:30", "04:35", "04:51", "05:16", "05:55", "06:12", "06:35", "Last"},
                    
        {"12903","18.45", "19.18", "22.02", "23.44", "00.50", "01.40", "02.06", "03.35", "04.28", "05.25", "05.50", "06.10", "07.20", "08.30", "09.15", "09.40", "09.55", "10.25", "11.00", "11.45", "13.17", "14.05", "14.45", "15.30", "15.37", "15.55", "16.20", "17.40", "18.08", "19.10", "20.53", "22.05", "22.38", "Last"},
                    
        {"15211","17.20", "17.30", "19.03", "19.15", "19.33", "20.20", "20.55", "21.12", "21.22", "21.34", "21.54", "22.20", "22.39", "22.56", "23.30", "23.48", "00.20", "02.00", "03.50", "04.52", "06.20", "07.20", "10.20", "10.55", "11.37", "13.13", "14.13", "15.55", "17.20", "17.57", "19.15", "19.43", "21.00", "21.26", "21.50", "22.41", "23.06", "23.22", "23.42", "00.03", "00.20", "00.53", "Last"},
                    
        {"14631","19.05", "19.20", "20.15", "20.44", "21.07", "21.55", "22.05", "23.00", "23.26", "00.20", "00.48", "00.56", "01.52", "02.38", "03.22", "04.55", "05.11", "05.31", "06.10", "06.30", "07.03", "07.49", "Last"},

        {"20807",  "00:25", "01:20", "02:30", "03:42", "04:40", "05:00", "05:45", "06:50", "07:20", "08:40", "10:00", "10:32", "11:35", "13:15", "14:15", "14:53", "15:53", "16:24", "16:39", "17:17", "17:37", "18:45", "20:27", "21:25", "21:46", "22:12", "23:10", "00:55", "02:25", "03:30", "04:10", "04:45", "06:01", "07:20", "07:47", "08:57", "11:05", "11:55", "14:06", "14:50", "16:03", "18:15", "19:56", "21:33", "22:06", "Last"},
                        
        {"12317","07.40", "10.37", "11.43", "12.10", "13.17", "14.00", "14.31", "15.25", "16.10", "19.40", "20.40", "22.48", "02.40", "06.16", "07.58", "09.20", "11.30", "12.50", "13.27", "14.33", "15.45", "16.20", "Last"},
            
        {"12357","12.10", "14.52", "16.00", "16.36", "18.43", "19.45", "21.15", "22.15", "02.40", "06.16", "07.58", "11.30", "12.50", "14.33", "15.45", "16.20", "Last"},

        {"12483","04.50", "05.50", "06.25", "07.35", "09.40", "11.10", "12.20", "13.40", "15.00", "16.05", "17.25", "19.02", "23.40", "04.55", "06.27", "11.00", "12.45", "15.28", "17.11", "20.53", "23.56", "05.37", "06.25", "09.10", "10.56", "11.55", "12.53", "Last"},
                
        {"12013","16.30", "18.53", "19.27", "20.19", "20.50", "21.16", "21.47", "Last"},
                
        {"12241", "16.40", "16.52", "18.46", "19.18", "19.55", "20.29", "Last"},
                
        {"22125","17.50", "00.12", "04.33", "05.52", "08.35", "12.10", "15.00", "16.36", "17.40", "18.13", "Last"},

        {"12715", "09.30", "10.02", "10.40", "11.12", "12.25", "13.30", "16.35", "17.25", "18.05", "18.40", "19.20", "20.10", "21.45", "00.15", "02.40", "04.32", "05.13", "06.38", "07.16", "07.47", "08.18", "09.05", "09.43", "10.20", "12.02", "12.37", "13.20", "14.32", "14.57", "15.22", "16.48", "17.10", "17.43", "17.56", "18.57", "19.28", "20.05", "20.40", "Last"},
                    
        {"12203","14.30", "14.50", "15.52", "16.26", "17.00", "17.29", "18.00", "18.55", "19.55", "21.25", "22.20", "00.45", "06.00", "07.37", "09.31", "11.10", "12.27", "14.05", "16.54", "18.36", "19.07", "19.38", "20.11", "Last"},
                    
        {"19325", "19.45", "20.57", "21.50", "22.17", "23.27", "01.00", "01.50", "03.05", "06.15", "08.25", "09.05", "10.55", "11.40", "12.20", "13.04", "13.45", "14.07", "15.20", "15.48", "16.54", "17.31", "18.36", "19.38", "20.11", "Last"},
          
        {"12497", "06.40", "07.22", "07.52", "08.16", "08.41", "10.07", "10.28", "10.56","11.50", "12.21", "12.55", "13.25", "Last"},
            
        {"18103","21.10", "23.02", "00.15", "01.18", "02.18", "04.00", "04.26", "04.49", "05.07", "05.24","05.58", "07.10", "08.10", "09.38", "11.45", "15.15", "19.16", "21.00", "23.05", "23.36","00.35", "01.03", "02.16", "03.54", "05.10", "05.43", "Last"},
        
    };
    
            
            
            
    
    std::vector<std::vector<std::string>> arrivalrarrays = {
        
        {"19225","First", "06.30", "07.43", "08.03", "09.00", "10.09", "12.00", "12.22", "15.00", "15.28", "16.05", "16.27", "17.01", "18.20", "18.52", "19.21", "19.40", "20.20", "21.18", "21.41", "21.51", "22.38", "23.10", "00.07", "00.50"},
        
        {"19226","First", "21.48", "22.55", "00.01", "00.18", "01.02", "01.28", "02.00"},
        
        {"18101","First", "18.01", "18.50", "19.55", "20.40", "21.07", "21.33", "21.58", "22.23", "22.58", "23.23", "00.16", "00.31", "01.00", "01.14", "01.36", "02.00", "04.40", "05.30", "07.35", "08.07", "08.26", "09.00", "09.45", "11.10", "13.00", "14.10", "15.15", "16.00", "16.45", "17.58", "20.18", "21.10", "21.39", "22.10", "22.46", "23.13", "23.38", "23.56", "01.58", "02.53", "05.06", "05.30", "05.58", "06.24", "06.43", "07.17", "08.00"},
        
        {"18309","First", "11.23", "11.55", "12.56", "13.25", "14.27", "15.04", "15.44", "16.50", "17.15", "18.35", "20.00","20.40", "21.07", "21.33", "21.58", "22.23", "22.58", "23.23", "00.16", "00.31", "01.00", "01.14", "01.36","02.00", "04.40", "05.30", "07.35", "08.07", "08.26", "09.00", "09.45", "11.10", "13.00", "14.10", "15.15","16.00", "16.45", "17.25", "17.58", "20.18", "21.10", "21.39", "22.10", "22.46", "23.13", "23.38", "23.56","01.58", "02.53", "05.06", "05.30", "05.58", "06.24", "06.43", "07.17", "08.00"},
        
        {"22430","First", "07.25", "07.37", "07.52", "08.11", "09.00"},
        
        {"22429","First", "09.18", "09.42", "10.07", "11.10", "11.50", "12.55", "13.58", "14.35", "15.20"},
        
        {"19416","First", "11.09", "12.26", "14.20", "15.48", "17.20", "11.11", "12.32", "14.45", "15.50", "17.45"},
        
        {"18310","First", "14.53", "15.19", "16.32", "17.32", "17.50", "18.06", "18.26", "19.22"},
        
        {"18102","First", "14.53", "15.19", "16.32", "17.32", "17.50", "18.06", "18.26", "19.22"},
        
        {"19415","First", "20.37", "21.35", "23.00", "00.05", "01.28", "01.43", "02.30", "03.40", "04.50", "05.28","06.10", "07.10", "07.36", "08.16", "08.48", "10.07", "10.30", "11.30", "12.40", "13.50", "15.20","16.55", "18.55", "21.25", "22.21", "23.20"},
        
        {"14615","First", "00.36", "01.00", "02.42", "04.45", "05.25", "05.51","06.55", "07.31", "08.40", "09.31", "09.58", "10.28", "12.13","12.50", "13.17", "13.53", "15.00"},
        
        {"12459","First", "14.30", "15.00", "15.24", "16.04", "17.00", "17.15", "17.32","17.55", "19.01", "19.24", "19.44", "20.25", "21.01", "22.00"},
        
        {"14617","First", "06.47", "07.08", "08.10", "08.56", "09.08", "10.03", "10.15","10.35", "10.56", "11.25", "11.58", "12.12", "12.24", "12.39", "12.50","13.02", "13.15", "13.35", "13.48", "14.26", "15.50", "16.40", "17.05","17.28", "18.00", "18.25", "20.10", "21.24", "22.50", "23.54", "01.58","03.01", "05.18", "06.16", "07.02", "07.50", "08.34", "09.13", "10.30","11.01", "11.55", "12.25", "12.46", "13.34", "13.51", "14.15", "14.35","15.06", "15.42", "16.40"},
        
        {"12053","First", "15.26", "16.15", "16.46", "17.43", "18.31", "19.30","20.04", "20.40", "21.16", "22.20"},
        
        {"12925","First", "11.55", "13.08", "13.41", "14.06", "14.45", "15.47","16.32", "17.30", "18.58", "19.50", "20.17", "21.40", "22.55","00.01", "00.42", "01.45", "03.08", "04.20", "04.53", "05.23","06.08", "07.30", "09.27", "09.59", "10.40", "11.19", "11.50","12.23", "12.49", "13.14", "14.20", "15.20", "15.35", "17.35","18.14", "18.33", "18.45", "19.21", "20.10"},

        {"15707","First", "23.06", "23.21", "23.38", "23.53", "00.33", "00.53","01.38", "02.30", "04.00", "04.18", "04.34", "05.15", "06.20","06.35", "07.06", "08.40", "09.40", "10.06", "10.45", "12.15","13.01", "13.28", "14.18", "15.10", "16.33", "17.28", "17.58","19.13", "19.50", "21.35", "22.30", "23.10", "23.52", "00.18","00.52", "02.03", "02.26", "02.55", "04.22", "04.55", "05.21","05.46", "06.45", "07.14", "07.35", "07.48", "08.40", "09.04","09.40", "10.30", "11.11", "12.20"},
        
        {"04653", "First", "10.30", "14.05", "15.05", "17.25", "20.40", "02.40", "07.35", "10.42", "16.20"},
        
        {"11057","First", "23:37", "00:02", "00:32", "01:28", "02:54", "03:05", "04:07", "05:03", "05:33","06:18", "06:50", "07:14", "07:29", "07:48", "08:13", "09:20", "09:41", "10:09", "10:44","11:13", "11:27", "11:51", "12:40", "13:08", "13:22", "14:11", "14:25", "15:03", "15:30","16:13", "16:33", "16:50", "17:22", "17:50", "18:22", "18:44", "19:14", "19:36", "20:20","20:52", "21:16", "21:54", "22:28", "23:13", "23:50", "00:55", "01:30", "02:30", "02:54","03:14", "03:40", "04:08", "04:28", "04:44", "04:57", "05:12", "05:26", "05:52", "06:05","06:21", "06:41", "07:45", "08:09", "08:38", "09:05", "09:39", "10:22", "10:58", "11:31","12:45", "13:09", "13:43", "14:02", "14:15", "14:51", "15:35", "16:15"},
        
        {"12407","First", "10.18", "11.45", "13.45", "15.20", "16.10", "17.05", "18.45", "19.40", "20.44", "21.55", "03.45", "08.40", "11.57", "13.20", "14.55", "15.57", "16.33", "17.35"},

        {"04651", "First", "05.25", "07.00", "08.20", "11.10", "16.55", "22.30", "03.55", "07.00", "10.10", "14.45"},
        
        {"22445","First", "18.11", "23.04", "00.45", "02.42", "03.06", "03.57", "05.18", "05.44", "06.55", "07.34", "08.05", "08.41", "09.30"},
        
        {"22423","First", "11.21", "11.48", "12.38", "13.20", "16.08", "18.13", "19.14", "20.52", "00.25", "02.03", "03.44", "04.29", "05.05", "05.41", "06.30"},
        
        {"14673","First", "07.32", "07.43", "07.55", "08.11", "08.55", "09.13", "09.27", "10.25", "11.11", "11.45", "12.40", "14.30", "15.30", "15.52", "16.08", "16.30", "16.58", "19.05", "19.53", "20.23", "20.49", "21.20", "22.00", "23.53", "00.45", "03.19", "04.20", "05.13", "06.05", "06.43", "07.44", "08.30", "09.12", "10.10", "10.46", "11.40", "11.56", "12.33", "12.56", "13.05", "13.15", "14.06", "14.30", "14.50", "15.09", "15.23", "16.02", "17.00"},
            
        {"14649","First", "07.32", "07.43", "07.55", "08.11", "08.55", "09.13", "09.27", "10.25", "11.11", "11.45", "12.40", "14.30", "15.30", "15.52", "16.08", "16.30", "16.58", "19.05", "19.53", "20.23", "20.49", "21.20", "22.00", "23.53", "00.45", "03.19", "04.20", "05.13", "06.05", "06.43", "07.44", "08.30", "09.12", "10.10", "10.46", "11.40", "11.56", "12.33", "12.56", "13.05", "13.15", "14.06", "14.30", "14.50", "15.09", "15.23", "16.02", "17.00"},
        
        {"19611", "First", "18.25", "19.55", "20.18", "20.29", "21.05", "21.31", "21.44", "21.58", "22.25", "22.51", "23.58", "01.15", "02.15", "03.50", "04.23", "05.50", "06.24", "06.40", "07.01", "08.00", "08.49", "09.22", "09.49", "11.10", "11.59", "12.30", "13.06", "14.40"},
        
        {"14603", "First", "17.11", "17.32", "18.15", "18.30", "18.55", "19.11", "19.26", "20.15", "21.10", "22.10", "22.23", "00.15", "01.15", "02.30", "04.10", "04.57", "05.26", "06.20", "06.55", "08.10", "11.10", "13.28", "14.25", "16.07", "17.05", "17.39", "20.15", "22.00", "22.45", "23.46", "00.50", "01.28", "02.20"},
        
        {"12379","First", "14.39", "15.25", "16.02", "16.30", "17.10", "20.00", "21.06", "22.30", "03.05", "09.05", "11.50", "13.23", "14.30", "15.06", "15.50"},
        
        {"14506","First", "07.34", "07.43", "08.08", "08.23", "08.38", "08.48", "09.23", "10.28", "11.35", "12.12", "13.05"},
            
        {"12421","First", "11.30", "12.59", "13.49", "15.55", "16.29", "17.03", "20.15", "22.40", "00.20", "02.15", "04.00", "05.08", "06.45", "10.10", "11.48", "12.57", "13.43", "14.23", "14.48", "15.55", "16.34", "17.05", "17.40", "18.30"},

        {"15933", "First", "11.56", "12.42", "13.40", "14.45", "15.25", "16.10", "16.43", "16.59", "17.32", "19.15", "21.00", "23.15", "00.47", "01.15", "04.05", "08.50", "11.09", "12.40", "13.58", "15.00", "17.05", "18.35", "19.55", "22.20", "00.43", "02.08", "05.50", "08.32", "09.28", "11.02", "15.00", "16.25", "18.10", "19.15", "19.51", "20.35"},
            
        {"18237",  "First", "11:43", "11:51", "12:00", "12:07", "12:14", "12:30", "12:44", "12:58", "13:11","14:00", "14:38", "15:01", "15:23", "16:05", "16:53", "17:25", "17:49", "18:14", "18:47","19:02", "19:40", "20:08", "20:26", "20:42", "21:17", "22:00", "23:29", "23:43", "00:24","00:40", "01:00", "01:37", "04:10", "04:33", "05:23", "05:51", "06:10", "06:50", "07:15","07:46", "09:25", "10:09", "10:36", "10:50", "11:02", "11:52", "12:20", "12:58", "13:38","14:05", "15:30", "16:05", "16:18", "17:05", "17:25", "17:36", "18:50", "19:10", "19:23","19:50", "20:31", "20:44", "20:54", "21:04", "21:15", "21:35", "21:46", "22:11", "22:29","22:49", "00:00", "00:32", "00:39", "00:57", "01:35", "01:50", "02:05", "02:26", "02:34","02:43", "03:33", "03:57", "04:16", "04:33", "04:50", "05:26", "06:13", "06:55"},
            
        {"12031", "First", "09.41", "10.02", "11.08", "11.40", "12.06", "12.38", "13.30"},
            
        {"12029", "First", "09.41", "10.02", "11.08", "11.40", "12.06", "12.38", "13.30"},

        {"12411","First", "06.45", "07.17", "07.36", "08.05", "08.58", "09.32", "10.00", "10.34", "11.30"},
                
        {"19613","First", "18.25", "19.55", "20.18", "20.29", "21.05", "21.31", "21.44", "21.58", "22.25", "22.51", "23.58", "01.15", "02.25", "04.19", "05.01", "05.32", "06.01", "07.40", "08.20", "08.57", "09.36", "10.30"},
                
        {"15531","First", "03.31", "04.06", "04.20", "05.02", "05.20", "06.15", "07.15", "08.10", "08.23", "10.15", "11.15", "12.00", "12.30", "14.25", "15.43", "17.05", "20.10", "00.00", "01.40", "03.44", "05.00", "06.27", "07.15", "09.49", "11.10", "12.25", "13.50"},
                
        {"13005","First", "20.17", "21.10", "21.29", "21.51", "22.18", "23.00", "23.29", "00.50", "01.30", "02.00", "02.33", "03.00", "03.40", "04.03", "04.32", "05.04", "05.26", "05.43", "06.05", "06.16", "08.05", "08.59", "09.15", "10.03", "10.33", "10.58", "11.35", "12.18", "12.33", "12.49", "13.20", "13.53", "15.40", "17.10", "17.39", "18.58", "20.03", "20.58", "21.52", "22.52", "23.10", "23.30", "00.13", "00.36", "01.35", "02.11", "03.10", "03.40", "05.35", "05.59", "06.27", "06.49", "07.05", "07.26", "07.43", "08.40"},
            
        {"14653","First", "01:23", "02:31", "02:50", "03:11", "03:28", "04:25", "04:49", "05:14", "05:50", "06:10", "06:33", "07:40"},

        {"12903","First", "19.15", "19.15", "23.34", "00.48", "01.38", "02.04", "03.30", "04.23", "05.23", "05.48", "06.08", "07.10", "08.25", "09.10", "09.38", "09.53", "10.23", "10.58", "11.43", "13.15", "13.50", "14.43", "15.25", "15.35", "15.53", "16.18", "17.32", "18.06", "19.05", "20.43", "21.55", "22.36", "23.40"},
                    
        {"15211","First", "17.28", "18.38", "19.13", "19.31", "20.15", "20.53", "21.10", "21.20", "21.32", "21.52", "22.18", "22.37", "22.54", "23.25", "23.46", "00.17", "01.55", "03.40", "04.49", "06.10", "07.15", "10.10", "10.50", "11.35", "13.11", "14.11", "15.50", "17.18", "17.55", "19.06", "19.41", "20.50", "21.24", "21.48", "22.39", "22.56", "23.20", "23.40", "00.01", "00.15", "00.51", "01.45"},
                    
        {"14631", "First", "19.18", "20.13", "20.42", "21.05", "21.45", "22.03", "22.35", "23.21", "00.10", "00.46", "00.54", "01.45", "02.32", "03.20", "04.46", "05.09", "05.29", "06.08", "06.25", "07.01", "07.47", "08.20"},

        {"20807","First", "01:15", "02:28", "03:40", "04:35", "04:58", "05:43", "06:40", "07:15", "08:38", "09:40", "10:30", "11:33", "12:55", "14:10", "14:51", "15:51", "16:22", "16:37", "17:12", "17:35", "18:30", "20:25", "21:20", "21:44", "22:10", "23:08", "00:45", "02:23", "03:25", "04:09", "04:43", "05:59", "07:15", "07:45", "08:55", "11:00", "11:53", "14:04", "14:30", "16:01", "18:10", "19:46", "21:28", "22:04", "23:00"},
                        
        {"12317", "First", "10.32", "11.41", "12.08", "13.12", "13.58", "14.29", "15.20", "16.00", "19.30", "20.30", "22.46", "02.30", "06.14", "07.50", "09.18", "11.20", "12.45", "13.25", "14.23", "15.40", "16.18", "17.20"},
            
        {"12357","First", "14.50", "15.55", "16.34", "18.38", "19.43", "21.05", "22.10", "02.30", "06.14", "07.50", "11.20", "12.45", "14.23", "15.40", "16.18", "17.20"},

        {"12483","First", "05.47", "06.23", "07.32", "09.35", "11.07", "12.15", "13.37", "14.57", "16.03", "17.20", "19.00", "23.30", "04.50", "06.25", "10.55", "12.35", "15.23", "17.03", "20.48", "23.51", "05.35", "06.10", "09.03", "10.46", "11.50", "12.51", "13.50"},
                
        {"12013","First", "18.51", "19.26", "20.16", "20.48", "21.14", "21.45", "22.40"},
                
        {"12241","First", "16.50", "18.39", "19.16", "19.50", "20.27", "21.15"},
                
        {"22125", "First", "00.02", "04.25", "05.50", "08.30", "11.55", "14.55", "16.26", "17.35", "18.11", "19.00"},

        {"12715","First", "10.00", "10.35", "11.11", "12.20", "13.25", "16.30", "17.23", "18.04", "18.38", "19.15", "20.08", "21.40", "00.05", "02.35", "04.30", "05.11", "06.30", "07.14", "07.45", "08.16", "09.03", "09.38", "10.18", "12.00", "12.35", "13.05", "14.30", "14.55", "15.20", "16.40", "17.09", "17.42", "17.54", "18.47", "19.26", "20.00", "20.38", "21.40"},
                    
        {"12203","First", "14.48", "15.50", "16.24", "16.50", "17.27", "17.55", "18.50", "19.50", "21.20", "22.15", "00.35", "05.50", "07.35", "09.28", "11.02", "12.25", "13.55", "16.49", "18.28", "19.05", "19.33", "20.09", "20.55"},
                    
        {"19325","First", "20.55", "21.48", "22.15", "23.25", "00.58", "01.40", "03.03", "06.10", "08.20", "09.00", "10.53", "11.25", "12.18", "13.02", "13.43", "14.05", "15.00", "15.46", "16.40", "17.29", "18.28", "19.33", "20.09", "20.55"},
                 
        {"12497","First", "07.20", "07.50", "08.14", "08.39", "10.02", "10.26", "10.54","11.44", "12.19", "12.50", "13.23", "14.15"},
            
        {"18103","First", "23.00", "00.10", "01.13", "02.16", "03.55", "04.24", "04.47", "05.05", "05.22","05.56", "07.00", "08.00", "09.36", "11.40", "15.05", "19.14", "20.52", "23.03", "23.34","00.25", "01.01", "02.03", "03.44", "05.05", "05.41", "06.30"},
        
        
        
    };
    
    
    
    
    
    
    
    
    
    std::cout<<"\n                                                                   ****  WELCOME TO INDIAN RAILWAYS  ****\n\n\n";
 
    int n;
    std::cout << "Press 1 for choosing Destination and 2 for choosing Boarding Station \n";
    
    //ADMIN MODE  //ADMIN MODE  //ADMIN MODE  //ADMIN MODE  //ADMIN MODE  //ADMIN MODE  //ADMIN MODE  //ADMIN MODE  //ADMIN MODE  //ADMIN MODE  //ADMIN MODE
    admin();
    cout<<"For ADMIN MODE , Enter Emp ID & Password \n";
    //admin();
    
    int user= 143001;
    string pswrd="password";
    string tempp;
    cout<<" : ";
    cin>>n;
    
    if(n==user){
        admin();
        cout<<"Enter password : ";
        admin();
        cin>>tempp;
        
        
        if(tempp==pswrd){
           
            adminmode();
            int tm;
            cin>>tm;
            
            if(tm==1){
                ifstream trni;
                trni.open("trainsdata.txt");
                
                if (!trni.is_open()) {
                    cout << "Can't Load History" << std::endl;
                } else {
                    string p;
                    int count=1;
                    string last;
                    for (string line; getline(trni, line); p = line) {
                        admin();
                        cout<<"Hitory at index "<<count << ": " << p << endl;
                    count++;}
                trni.close();
                    return main();
                }}
            
            
            
            else if(tm==2){
                
                ofstream file("trainsdata.txt", ios::trunc);
                admin();
                cout<<"History Deleted Succesfully";
                    if (file.is_open()) {
                        file.close();
                        return main();
              }}
            
            else if(tm==3){
                return main();}
            
            else{
                admin();
                cout<<"Error\n";
                admin();
                return main();
                }}
        
        else{
            admin();
            cout<<"Invalid Cridentials";
            return main();
        }}
    
    

    
    // Getting user input
    string st;
    getline(cin, st);

    //destination//destination//destination//destination//destination//destination//destination//destination//destination//destination//destination
        if (n==1)
        {
            
            std::cout << "\nEnter Destination : ";
            std::getline(std::cin, st);
            int count=0;
            std::string s1 = lc(st);
            
            
            
            if(lc(st)=="amritsar"){
                cout<<"Boarding & Destination stations can't be same.\n\n";
                return main();
            }
            if (sn(s1, arrays)) {
                std::cout<<"Trains between amritsar and "<<s1<<" are:\n";
                for (const auto& array : arrays) {
                    if (std::find(array.begin(), array.end(), s1) != array.end()) {
                        std::cout << array.front() << std::endl;
                        count++;
                    }
                }
            }
            
            if (count == 0) {
                std::cout << "(" << count << ") Trains Found\n";
                std::cout << "\nNo Direct Trains Found, Please change the Station name.\n\n\n";
                
                return main();
            } else {
                std::cout << "(" << count << ") Trains Found\n\n";
            }
        }
        
        
        
        
        //boarding //boarding //boarding //boarding //boarding //boarding //boarding //boarding //boarding //boarding //boarding //boarding //boarding
        else if (n==2)
        {
            std::cout<<"\nEnter Boarding Station : ";
            std::getline(std::cin, st);
            int count=0;
            std::string s1 = lc(st);
            if(lc(st)=="amritsar"){
                cout<<"Boarding & Destination stations can't be same.\n\n";
                return main();
            }
            
            if (sn(s1, rarrays)) {
                std::cout<<"Trains between "<<s1<<" and amritsar are:\n";
                for (const auto& array : rarrays) {
                    if (std::find(array.begin(), array.end(), s1) != array.end()) {
                        std::cout << array.front() << std::endl;
                        count++;
                    }
                }
            }
            
            
            if (count == 0) {
                std::cout << "(" << count << ") Trains Found\n";
                std::cout << "\nNo Direct Trains Found, Please change the Station name.\n\n\n";
                
                return main();
            } else {
                std::cout << "(" << count << ") Trains Found\n";
            }
        }
        
        else{
            cout<<"\nPlease Enter a Valid Option\n\n";
            return main();
        }
        
        
        
        //read from a file  //read from a file  //read from a file  //read from a file  //read from a file  //read from a file  //read from a file
       
        ifstream trni;
        trni.open("trainsdata.txt");
        
        if (!trni.is_open()) {
            cout << "Can't Load History" << std::endl;
            
        } else {
            string p;
            string last;
            for (string line; getline(trni, line); p = line) {}
            if (!p.empty()) {
                cout << "\nLast Search : " << p << endl;}
            trni.close();
        }
        
        
        
        // trn number;  // trn number; // trn number; // trn number; // trn number; // trn number; // trn number; // trn number;
        cout << "\nEnter Train Number: ";
        cin >> trn;
        
        
        // Storing in File// Storing in File// Storing in File// Storing in File// Storing in File// Storing in File
        std::fstream trno;
        trno.open("trainsdata.txt",ios::app | ios::out);
        
        if (!trno.is_open()) {
            // std::cout << "\nHistory isn't saved\n";
        } else {
            trno << trn << "\n";
            std::cout << "\n";
            trno.close();
        }
        
        
        
        {
            //DEPART   //DEPART   //DEPART   //DEPART   //DEPART   //DEPART   //DEPART   //DEPART   //DEPART   //DEPART   //DEPART   //DEPART   //DEPART   //DEPART   //DEPART
            if(trn==12926)
            {std::cout<<"Paschim SF Express (PT) has 23 coaches that contains 1 FIRST AC coach, 2 SECOND AC coach, 5 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--H1--A1--A2--B1--B2--B3--B4--B5--PC--S1--S2--S3--S4--S5--S6--S7--S8--EOG--HCP";
            }else if(trn==4654){
                std::cout<<"Amritsar - New Jalpaiguri Clone SF Special has 20 coaches that contains 1 SECOND SEATING coach, 9 THIRD AC coach, 0 AC CHAIR CAR coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--DL1--S1--S2--S3--S4--S5--S6--SE1--ME1--B1--B2--B3--B4--B5--B6--B7--B8--B9--EOG";
            }else if(trn==19225){
                std::cout<<"Jodhpur - Jammu Tawi Express has 19 coaches that contains 1 SECOND AC coach, 4 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--S8--S7--S6--S5--S4--S3--S2--S1--B4--B3--B2--B1--A1--GS--GS--SLR";
            }else if(trn==19326){
                std::cout<<"Amritsar - Indore Express has 23 coaches that contains 2 SECOND AC coach, 6 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--S8--S7--S6--S5--S4--S3--S2--S1--B6--B5--B4--B3--B2--B1--A2--A1--GS--GS--EOG";
            }else if(trn==19226){
                std::cout<<"Jammu Tawi - Jodhpur Express has 19 coaches that contains 1 SECOND AC coach, 4 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--A1--B1--B2--B3--B4--S1--S2--S3--S4--S5--S6--S7--S8--GS--SLR";
            }else if(trn==12204){
                std::cout<<"Amritsar - Saharsa Garib Rath Express (PT) has 19 coaches that contains 14 THIRD AC coach, 4 AC CHAIR CAR coach. The full coach composition is: Engine--GD2--G12--G11--G10--G9--G8--G7--G6--G5--G4--G3--G2--G1--J4--J3--J2--J1--GD1";
            }else if(trn==22126){
                std::cout<<"Amritsar - Nagpur AC SF Express has 17 coaches that contains 1 FIRST AC coach, 4 SECOND AC coach, 9 THIRD AC coach. The full coach composition is: Engine--EOG--B1--B2--B3--B4--B5--B6--B7--B8--B9--A1--A2--A3--A4--H1--EOG";
            }else if(trn==12014){
                std::cout<<"Amritsar - New Delhi Shatabdi Express has 19 coaches that contains 14 AC CHAIR CAR coach, 2 EXECUTIVE CLASS coach. The full coach composition is: Engine--EOG--K1--E1--C14--C13--C12--C11--C10--C9--C8--C7--C6--C5--C4--C3--C2--C1--EOG";
            }else if(trn==12242){
                std::cout<<"Amritsar - Chandigarh SF Express has 12 coaches that contains 6 SECOND SEATING coach, 1 AC CHAIR CAR coach. The full coach composition is: Engine--EOG--GS--C1--D6--D5--D4--D3--D2--D1--GS--SLR";
            }else if(trn==12716){
                std::cout<<"Sachkhand Express has 23 coaches that contains 1 FIRST AC coach, 1 SECOND AC coach, 6 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--HCP--GS--H1--A1--B1--B2--B3--B4--B5--B6--PC--S1--S2--S3--S4--S5--S6--S7--S8--GS--EOG";
            }else if(trn==12318){
                std::cout<<"Akal Takht Express (PT) has 23 coaches that contains 1 FIRST AC coach, 1 SECOND AC coach, 6 THIRD AC coach, 10 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--HA1--A1--B6--B5--B4--B3--B2--B1--S10--S9--S8--S7--S6--S5--S4--S3--S2--S1--GS--GS--EOG";
            }else if(trn==12358){
                std::cout<<"Durgiana Express has 23 coaches that contains 1 FIRST AC coach, 2 SECOND AC coach, 6 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--HA1--A2--A1--B6--B5--B4--B3--B2--B1--S8--S7--S6--S5--S4--S3--S2--S1--GS--GS--GS--SLR";
            }else if(trn==12484){
                std::cout<<"Amritsar - Kochuveli Weekly SF Express has 23 coaches that contains 2 SECOND AC coach, 6 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GS--GS--GS--GS--S7--S6--S5--S4--S3--S2--S1--PC--B6--B5--B4--B3--B2--B1--A2--A1--EOG";
            }else if(trn==14616){
                std::cout<<"Amritsar - Lal Kuan Express has 20 coaches that contains 1 SECOND AC coach, 3 THIRD AC coach, 9 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GS--GS--A1--B1--B2--B3--S1--S2--S3--S4--S5--S6--S7--S8--S9--GS--GS--EOG";
            }else if(trn==12460){
                std::cout<<"Amritsar - New Delhi InterCity Express has 21 coaches that contains 6 SECOND SEATING coach, 2 AC CHAIR CAR coach. The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--C1--C2--D1--D2--D3--D4--D5--D6--GS--GS--GS--GS--GS--EOG";
            }else if(trn==14618){
                std::cout<<"Amritsar - Banmankhi Jan Sewa Express (UnReserved) has 17 GENERAL coaches . The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS ";
            }else if(trn==12054)
            {std::cout<<"Amritsar - Haridwar Jan Shatabdi Express has 12 coaches that contains 10 SECOND SEATING coach, 1 AC CHAIR CAR coach. The full coach composition is: Engine--D7--C1--DE1--DE2--DE3--D1--D2--D3--D4--D5--D6";
            }else if(trn==15708){
                std::cout<<"Amrapali Express has 23 coaches that contains 1 SECOND AC coach, 3 THIRD AC coach, 10 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GS--GS--GS--S10--S9--S8--S7--S6--S5--S4--S3--S2--S1--B2--B1--BE1--A1--GS--GS--GS--SLR";
            }else if(trn==18101){
                std::cout<<"Tatanagar - Jammu Tawi Express (PT) has 22 coaches that contains 2 SECOND AC coach, 7 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--S1--S2--S3--S4--S5--PC--S6--S7--B1--B2--B3--B4--B5--B6--B7--A1--A2--GS--SLR";
            }else if(trn==18309){
                std::cout<<"Sambalpur - Jammu Tawi Express has 21 coaches that contains 1 SECOND AC coach, 3 THIRD AC coach, 9 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--A1--B1--B2--B3--PC--S1--S2--S3--S4--S5--S6--S7--S8--S9--GS--GS--SLR";
            }else if(trn==11058){
                std::cout<<"Amritsar - Mumbai CSMT Express has 19 coaches that contains 1 SECOND AC coach, 4 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--RMS--A1--B1--B2--B3--B4--S1--S2--S3--S4--S5--S6--S7--S8--GS--SLR";
            }else if(trn==22430){
                std::cout<<"Pathankot - Delhi SF Express has 19 coaches that contains 7 SECOND SEATING coach, 2 AC CHAIR CAR coach. The full coach composition is: Engine--EOG--C1--C2--D1--D2--D3--D4--D5--D6--GS--GS--GS--GS--GS--GS--GS--GS--DL1";
            }else if(trn==12408){
                std::cout<<"Amritsar - New Jalpaiguri Karambhoomi Express (UnReserved) has 17 GENERAL coaches. The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS ";
            }else if(trn==4652){
                std::cout<<"Amritsar - Jaynagar Clone Special has 19 coaches that contains 12 THIRD AC coach, 4 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--B12--B11--B10--B9--B8--B7--B6--B5--B4--B3--B2--B1--S4--S3--S2--S1--EOG";
            }else if(trn==18101){
                std::cout<<"Tatanagar - Jammu Tawi Express (PT) has 22 coaches that contains 2 SECOND AC coach, 7 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--S1--S2--S3--S4--S5--PC--S6--S7--B1--B2--B3--B4--B5--B6--B7--A1--A2--GS--SLR";
            }else if(trn==22446){
                std::cout<<"Amritsar - Kanpur Central Weekly SF Express has 23 coaches that contains 1 SECOND AC coach, 7 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--A1--B1--B2--B3--B4--B5--B6--B7--S8--S7--S6--S5--S4--S3--S2--S1--GS--GS--GS--GS--EOG";
            }else if(trn==22424){
                std::cout<<"Amritsar - Gorakhpur Jansadharan Express (UnReserved) has 17 GENERAL coaches. The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS ";
            }else if(trn==14650){
                std::cout<<"Saryu Yamuna Express has 25 coaches that contains 1 SECOND AC coach, 2 THIRD AC coach, 11 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--GS--GS--S1--S2--S3--S4--S5--S6--S7--S8--S9--SE1--SE2--B1--B2--AB1--GS--GS--GS--GS--SLR";
            }else if(trn==14674){
                std::cout<<"Shaheed Express has 25 coaches that contains 1 SECOND AC coach, 2 THIRD AC coach, 11 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GN--GN--GN--GN--S1--S2--S3--S4--S5--S6--S7--S8--S9--SE1--SE2--B1--B2--AB1--GN--GN--GN--GN--SLR";
            }else if(trn==19612){
                std::cout<<"Amritsar - Ajmer Express (via Firozpur) has 19 coaches that contains 1 SECOND AC coach, 4 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GS--GS--S1--S2--S3--S4--S5--S6--S7--B1--B2--B3--B4--A1--GS--GS--EOG";
            }else if(trn==14604){
                std::cout<<"Amritsar - Saharsa Jansadharan Express (Via Sirhind) (UnReserved) has 17 GENERAL coaches. The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS";
            }else if(trn==12380){
                std::cout<<"Amritsar - Sealdah Jallianwala Bagh Express has 23 coaches that contains 1 FIRST AC coach, 1 SECOND AC coach, 5 THIRD AC coach, 9 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GEN--GEN--GEN--S9--S8--S7--S6--S5--S4--S3--S2--S1--PC--B5--B4--B3--B2--B1--A1--HA1--SLR";
            }else if(trn==14505){
                std::cout<<"Amritsar-NangalDam Express, The full coach composition is:\nEngine--SLR--GEN--GEN--GEN--GEN--B2--B1--S3--S2--S1--GEN--GEN--GEN--GEN--SLR";
            }else if(trn==12422){
                std::cout<<"Amritsar - Hazur Sahib Nanded SF Express has 20 coaches that contains 1 SECOND AC coach, 3 THIRD AC coach, 9 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GS--GS--A1--B1--B2--B3--S1--S2--S3--S4--S5--S6--S7--S8--S9--GS--GS--EOG";
            }else if(trn==12498){
                std::cout<<"Shan-e-Punjab Express has 22 coaches that contains 14 SECOND SEATING coach, 3 AC CHAIR CAR coach. The full coach composition is: Engine--SLR--C1--C2--C3--D1--D2--D3--D4--D5--D6--D7--D8--D9--D10--D11--D12--D13--D14--GS--GS--EOG";
            }else if(trn==15934){
                std::cout<<"Amritsar - New Tinsukia Express (PT) has 23 coaches that contains 2 SECOND AC coach, 6 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GS--GS--A2--A1--B6--B5--B4--B3--B2--B1--PC--S7--S6--S5--S4--S3--S2--S1--GS--GS--EOG";
            }else if(trn==22429){
                std::cout<<"Delhi - Pathankot SF Express has 19 coaches that contains 7 SECOND SEATING coach, 2 AC CHAIR CAR coach. The full coach composition is: Engine--EOG--C1--C2--D1--D2--D3--D4--D5--D6--GS--GS--GS--GS--GS--GS--GS--GS--DL1";
            }else if(trn==18238){
                std::cout<< "Chhattisgarh Express (PT) has 22 coaches that contains 1 FIRST AC coach, 2 SECOND AC coach, 6 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--S1--S2--S3--S4--S5--S6--S7--PC--B1--B2--B3--B4--B5--B6--A1--A2--H1--EOG";
            }else if(trn==12030 || trn==12032){
                std::cout<<"Amritsar - New Delhi Swarna Jayanti Shatabdi Express has 20 coaches that contains 14 AC CHAIR CAR coach, 3 EXECUTIVE CLASS coach. The full coach composition is: Engine--EOG--E3--E2--E1--C14--C13--C12--C11--C10--C9--C8--C7--C6--C5--C4--C3--C2--C1--EOG";
            }else if(trn==12412){
                std::cout<<"Amritsar - Chandigarh Intercity Express has 15 coaches that contains 8 SECOND SEATING coach, 2 AC CHAIR CAR coach. The full coach composition is: Engine--EOG--GS--C2--C1--D8--D7--D6--D5--D4--D3--D2--D1--GS--SLR";
            }else if(trn==19614){
                std::cout<<"Amritsar - Ajmer Express (via Dhuri) has 21 coaches that contains 1 SECOND AC coach, 5 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GEN--GEN--S1--S2--S3--S4--S5--S6--S7--B1--B2--B3--B4--BE1--A1--GEN--GEN--GEN--EOG";
            }else if(trn==19416){
                std::cout<<"Shri Mata Vaishno Devi Katra - Ahmedabad Express has 21 coaches that contains 2 SECOND AC coach, 5 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GEN--GEN--S8--S7--S6--S5--S4--S3--S2--S1--B5--B4--B3--B2--B1--A2--A1--GEN--EOG";
            }else if(trn==13006){
                std::cout<< "Amritsar - Howrah Mail (PT) has 23 coaches that contains 1 FIRST AC coach, 1 SECOND AC coach, 5 THIRD AC coach, 9 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--B5--B4--B3--B2--B1--A1--HA1--PC--S9--S8--S7--S6--S5--S4--S3--S2--S1--GS--GS--GS--SLR";
            }else if(trn==12904){
                std::cout<<"Golden Temple Mail (PT) has 23 coaches that contains 1 FIRST AC coach, 2 SECOND AC coach, 5 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--HCP--SLR--GS--H1--A1--A2--B1--B2--B3--B4--B5--PC--S1--S2--S3--S4--S5--S6--S7--S8--GS--EOG";
            }else if(trn==15212){
                std::cout<<"Amritsar - Darbangha JanNayak Express (UnReserved) has 17 GENERAL coaches. The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS";
            }else if(trn==18310){
                std::cout<<"Jammu Tawi - Sambalpur Express has 22 coaches that contains 1 SECOND AC coach, 3 THIRD AC coach, 10 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--S9--S8--S7--S6--S5--S4--S3--S2--S1--SE1--PC--B3--B2--B1--A1--GS--GS--SLR";
            }else if(trn==18102){
                std::cout<<"Jammu Tawi - Tatanagar Express has 22 coaches that contains 2 SECOND AC coach, 7 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--A2--A1--B7--B6--B5--B4--B3--B2--B1--S7--S6--PC--S5--S4--S3--S2--S1--GS--SLR";
            }else if(trn==14632){
                std::cout<<"Amritsar - Dehradun Express has 19 coaches that contains 2 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--S8--S7--S6--S5--GS--B2--B1--S4--S3--S2--S1--GS--GS--GS--GS--GS--SLR";
            }else if(trn==19415){
                std::cout<<"Ahmedabad - Shri Mata Vaishno Devi Katra Express (PT) has 21 coaches that contains 2 SECOND AC coach, 5 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GEN--GEN--S8--S7--S6--S5--S4--S3--S2--S1--B5--B4--B3--B2--B1--A2--A1--GEN--EOG";
            }else if(trn==20808){
                std::cout<<"Hirakud SF Express has 19 coaches that contains 1 SECOND AC coach, 4 THIRD AC coach, 6 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--GS--B4--B3--B2--B1--A1--S6--PC--S5--S4--S3--S2--S1--GS--EOG";
            } else if(trn==14654){
                std::cout<<"Amritsar - Hisar Express has 17 GENERAL coaches. The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS";
            } else if(trn==18104){
                std::cout<<"Amritsar - Tatanagar Jallianwala Bagh Express has 23 coaches that contains 1 SECOND AC coach, 5 THIRD AC coach, 10 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--GS--S1--S2--S3--S4--S5--S6--S7--S8--S9--S10--PC--B1--B2--B3--B4--B5--A1--EOG";
            }
            
            
            
            //ARRIVAL  //ARRIVAL  //ARRIVAL  //ARRIVAL  //ARRIVAL  //ARRIVAL  //ARRIVAL  //ARRIVAL  //ARRIVAL  //ARRIVAL  //ARRIVAL  //ARRIVAL
            else if(trn==14653){
                std::cout<<"Hisar - Amritsar Express (UnReserved) has 17 GENERAL coaches. The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS";
            }else if(trn==15211){
                std::cout<<"Darbangha-Amritsar JanNayak Express (UnReserved) has 17 GENERAL coaches. The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS";
            }else if(trn==14603){
                std::cout<<"Saharsa-Amritsar Jansadharan Express (Via Sirhind) (UnReserved) has 17 GENERAL coaches. The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS";
            }else if(trn==18103){
                std::cout<<"Tatanagar - Amritsar Jallianwala Bagh Express has 23 coaches that contains 1 SECOND AC coach, 5 THIRD AC coach, 10 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--GS--S1--S2--S3--S4--S5--S6--S7--S8--S9--S10--PC--B1--B2--B3--B4--B5--A1--EOG";
            }else if(trn==22423){
                std::cout<<"Gorakhpur-Amritsar Jansadharan Express (UnReserved) has 17 GENERAL coaches. The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS ";
            }else if(trn==18237){
                std::cout<<"Chhattisgarh Express (PT) has 22 coaches that contains 1 FIRST AC coach, 2 SECOND AC coach, 6 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--S1--S2--S3--S4--S5--S6--S7--PC--B1--B2--B3--B4--B5--B6--A1--A2--H1--EOG";
            }else if(trn==14631){
                std::cout<<"Dehradun - Amritsar Express has 19 coaches that contains 2 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--S8--S7--S6--S5--GS--B2--B1--S4--S3--S2--S1--GS--GS--GS--GS--GS--SLR";
            }else if(trn==13005){
                std::cout<<"Howrah - Amritsar Mail (PT) has 23 coaches that contains 2 FIRST AC coach, 1 SECOND AC coach, 5 THIRD AC coach, 9 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GEN--GEN--GEN--S1--S2--S3--S4--S5--S6--S7--S8--S9--PC--HA1--A1--B1--B2--B3--B4--B5--EOG";
            }else if(trn==22445){
                std::cout<<"Kanpur Central - Amritsar Weekly SF Express (PT) has 23 coaches that contains 1 SECOND AC coach, 7 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--A1--B1--B2--B3--B4--B5--B6--B7--S8--S7--S6--S5--S4--S3--S2--S1--GS--GS--GS--GS--EOG";
            }else if(trn==19613){
                std::cout<<"Ajmer - Amritsar Express (via Dhuri) has 19 coaches that contains 1 SECOND AC coach, 4 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GEN--GEN--S1--S2--S3--S4--S5--S6--S7--B1--B2--B3--B4--A1--GEN--GEN--EOG";
            }else if(trn==12411){
                std::cout<<"Chandigarh - Amritsar Intercity Express has 15 coaches that contains 8 SECOND SEATING coach, 2 AC CHAIR CAR coach. The full coach composition is: Engine--SLR--GS--D1--D2--D3--D4--D5--D6--D7--D8--C1--C2--GS--EOG";
            }else if(trn==15707){
                std::cout<<"Amrapali Express has 23 coaches that contains 1 SECOND AC coach, 3 THIRD AC coach, 10 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GN--GN--GN--S1--S2--S3--S4--S5--S6--S7--S8--S9--S10--B1--B2--B3--A1--GN--GN--GN--EOG";
            }else if(trn==14506){
                std::cout<<"Amritsar-NangalDam Express, The full coach composition is:\nEngine--SLR--GEN--GEN--GEN--GEN--B2--B1--S3--S2--S1--GEN--GEN--GEN--GEN--SLR";
            }else if(trn==12031 || trn==12029){
                std::cout<<"New Delhi - Amritsar Swarna Jayanti Shatabdi Express has 20 coaches that contains 14 AC CHAIR CAR coach, 3 EXECUTIVE CLASS coach. The full coach composition is: Engine--EOG--C1--C2--C3--C4--C5--C6--C7--C8--C9--C10--C11--C12--C13--C14--E1--E2--E3--EOG";
            }else if(trn==12483){
                std::cout<<"Kochuveli - Amritsar Weekly SF Express (PT) has 23 coaches that contains 2 SECOND AC coach, 6 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--A1--A2--B1--B2--B3--B4--B5--B6--PC--S1--S2--S3--S4--S5--S6--S7--GS--GS--GS--GS--EOG";
            }else if(trn==15531){
                std::cout<<"Saharsa-Amritsar Jansadharan Express (Via Chandigarh) (UnReserved) has 17 GENERAL coaches. The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS";
            }else if(trn==15532){
                std::cout<<"Saharsa-Amritsar Jansadharan Express (Via Chandigarh) (UnReserved) has 17 GENERAL coaches. The full coach composition is: Engine--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--EOG";
            }else if(trn==12497){
                std::cout<<"Shan-e-Punjab Express has 22 coaches that contains 14 SECOND SEATING coach, 3 AC CHAIR CAR coach. The full coach composition is: Engine--EOG--GS--GS--D14--D13--D12--D11--D10--D9--D8--D7--D6--D5--D4--D3--D2--D1--C3--C2--C1--SLR";
            }else if(trn==19611){
                std::cout<<"Ajmer - Amritsar Express (via Firozpur) has 19 coaches that contains 1 SECOND AC coach, 4 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GEN--GEN--S1--S2--S3--S4--S5--S6--S7--B1--B2--B3--B4--A1--GEN--GEN--EOG";
            }else if(trn==4651){
                std::cout<<"Jaynagar - Amritsar Clone Special has 20 coaches that contains 9 THIRD AC coach, 0 AC CHAIR CAR coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--B9--B8--B7--B6--B5--B4--B3--B2--B1--ME1--SE1--S6--S5--S4--S3--S2--S1--EOG";
            }else if(trn==14615){
                std::cout<<"Lalkuan - Amritsar Express has 20 coaches that contains 1 SECOND AC coach, 3 THIRD AC coach, 9 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GS--GS--A1--B1--B2--B3--S1--S2--S3--S4--S5--S6--S7--S8--S9--GS--GS--EOG";
            }else if(trn==12379){
                std::cout<<"Sealdah - Amritsar Jallianwala Bagh Express (PT) has 23 coaches that contains 1 FIRST AC coach, 1 SECOND AC coach, 5 THIRD AC coach, 9 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--HA1--A1--B1--B2--B3--B4--B5--PC--S1--S2--S3--S4--S5--S6--S7--S8--S9--GEN--GEN--GEN--EOG";
            }else if(trn==11057){
                std::cout<<"Mumbai CSMT - Amritsar Express (PT) has 19 coaches that contains 1 SECOND AC coach, 4 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--S8--S7--S6--S5--S4--S3--S2--S1--B4--B3--B2--B1--A1--RMS--GS--SLR";
            }else if(trn==4653){
                std::cout<<"New Jalpaiguri - Amritsar Clone SF Special has 19 coaches that contains 12 THIRD AC coach, 4 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--B12--B11--B10--B9--B8--B7--B6--B5--B4--B3--B2--B1--S4--S3--S2--S1--EOG";
            }else if(trn==14617){
                std::cout<<"Banmankhi-Amritsar Jan Sewa Express (UnReserved) has 17 GENERAL coaches . The full coach composition is: Engine--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--EOG";
            }else if(trn==14649){
                std::cout<<"Saryu Yamuna Express has 25 coaches that contains 1 SECOND AC coach, 2 THIRD AC coach, 11 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--GS--GS--A1--B2--B1--SE2--SE1--S9--S8--S7--S6--S5--S4--S3--S2--S1--GS--GS--GS--GS--SLR";
            }else if(trn==14673){
                std::cout<<"Shaheed Express (PT) has 25 coaches that contains 1 SECOND AC coach, 2 THIRD AC coach, 11 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GS--GS--GS--GS--SE1--SE2--S1--S2--S3--S4--S5--S6--S7--S8--S9--AB1--B1--B2--GS--GS--GS--GS--SLR";
            }else if(trn==12317){
                std::cout<<"Akal Takht Express (PT) has 23 coaches that contains 1 FIRST AC coach, 1 SECOND AC coach, 6 THIRD AC coach, 10 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GEN--GEN--S1--S2--S3--S4--S5--S6--S7--S8--S9--S10--B1--B2--B3--B4--B5--B6--A1--HA1--EOG";
            }else if(trn==12357){
                std::cout<<"Durgiana Express (PT) has 23 coaches that contains 1 FIRST AC coach, 2 SECOND AC coach, 6 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--SLR--GEN--GEN--GEN--S1--S2--S3--S4--S5--S6--S7--S8--B1--B2--B3--B4--B5--B6--A1--A2--HA1--EOG";
            }else if(trn==12407){
                std::cout<<"New Jalpaiguri - Amritsar Karambhoomi Express (UnReserved) has 17 GENERAL coaches. The full coach composition is: Engine--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--GS--EOG ";
            }else if(trn==12421){
                std::cout<<"Hazur Sahib Nanded - Amritsar SF Express has 20 coaches that contains 1 SECOND AC coach, 3 THIRD AC coach, 9 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GS--GS--A1--B1--B2--B3--S1--S2--S3--S4--S5--S6--S7--S8--S9--GS--GS--EOG";
            }else if(trn==22125){
                std::cout<<"Nagpur - Amritsar AC SF Express has 17 coaches that contains 1 FIRST AC coach, 4 SECOND AC coach, 9 THIRD AC coach. The full coach composition is: Engine--EOG--H1--A4--A3--A2--A1--B9--B8--B7--B6--B5--B4--B3--B2--B1--EOG";
            }else if(trn==12925){
                std::cout<<"Paschim SF Express (PT) has 23 coaches that contains 1 FIRST AC coach, 2 SECOND AC coach, 5 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--HCP--EOG--GS--GS--S8--S7--S6--S5--S4--S3--S2--S1--PC--B5--B4--B3--B2--B1--A2--A1--H1--SLR";
            }else if(trn==15933){
                std::cout<<"New Tinsukia - Amritsar Express (PT) has 23 coaches that contains 2 SECOND AC coach, 6 THIRD AC coach, 7 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GN--GN--S1--S2--S3--S4--S5--S6--S7--PC--B1--B2--B3--B4--B5--B6--A1--A2--GN--GN--EOG";
            }else if(trn==12203){
                std::cout<<"Saharsa - Amritsar Garib Rath Express has 19 coaches that contains 14 THIRD AC coach, 4 AC CHAIR CAR coach. The full coach composition is: Engine--GD1--J1--J2--J3--J4--G1--G2--G3--G4--G5--G6--G7--G8--G9--G10--G11--G12--GD2";
            }else if(trn==19325){
                std::cout<<"Indore - Amritsar Express has 23 coaches that contains 2 SECOND AC coach, 6 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--GS--GS--A1--A2--B1--B2--B3--B4--B5--B6--S1--S2--S3--S4--S5--S6--S7--S8--GS--GS--SLR";
            }else if(trn==12241){
                std::cout<<"Chandigarh - Amritsar SF Express has 12 coaches that contains 6 SECOND SEATING coach, 1 AC CHAIR CAR coach. The full coach composition is: Engine--SLR--GS--D1--D2--D3--D4--D5--D6--C1--GS--EOG";
            }else if(trn==12715){
                std::cout<<"Sachkhand Express (PT) has 23 coaches that contains 1 FIRST AC coach, 1 SECOND AC coach, 6 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--HCP--GS--H1--A1--B1--B2--B3--B4--B5--B6--PC--S1--S2--S3--S4--S5--S6--S7--S8--GS--EOG";
            }else if(trn==12459){
                std::cout<<"New Delhi - Amritsar InterCity Express has 21 coaches that contains 6 SECOND SEATING coach, 2 AC CHAIR CAR coach. The full coach composition is: Engine--EOG--GS--GS--GS--GS--GS--D6--D5--D4--D3--D2--D1--C2--C1--GS--GS--GS--GS--GS--EOG";
            }else if(trn==12053){
                std::cout<<"Haridwar - Amritsar Jan Shatabdi Express has 12 coaches that contains 10 SECOND SEATING coach, 1 AC CHAIR CAR coach. The full coach composition is: Engine--D6--D5--D4--D3--D2--D1--DE3--DE2--DE1--C1--D7";
            }else if(trn==12013){
                std::cout<<"New Delhi - Amritsar Shatabdi Express has 19 coaches that contains 14 AC CHAIR CAR coach, 2 EXECUTIVE CLASS coach. The full coach composition is: Engine--EOG--C1--C2--C3--C4--C5--C6--C7--C8--C9--C10--C11--C12--C13--C14--E1--K1--EOG";
            }else if(trn==20807){
                std::cout<<"Hirakud SF Express (PT) has 18 coaches that contains 1 SECOND AC coach, 4 SECOND SEATING coach, 3 THIRD AC coach, 6 SLEEPER CLASS coach. The full coach composition is: Engine--EOG--D1--D2--S1--S2--S3--S4--S5--S6--PC--A1--B1--B2--B3--D3--D4--EOG";
            }else if(trn==12903){
                std::cout<<"Golden Temple Mail (PT) has 23 coaches that contains 1 FIRST AC coach, 2 SECOND AC coach, 5 THIRD AC coach, 8 SLEEPER CLASS coach. The full coach composition is: Engine--HCP--EOG--GS--S8--S7--S6--S5--S4--S3--S2--S1--PC--B5--B4--B3--B2--B1--A2--A1--H1--GS--SLR";
                
                
            }
            else{
                std::cout<<"No Matchings Found\n\n";
                return main();
            }
            
            //Tabular Data  //Tabular Data  //Tabular Data  //Tabular Data  //Tabular Data  //Tabular Data  //Tabular Data  //Tabular Data
            
            cout<<"\n\nTrain Time Table:\n\n";
            cout<<"┏━━━━━━┓━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓━━━━━━━━━━━━━━━━━━┓━━━━━━━━━━━━━━━━━━━━┓\n";
            cout<<"┃ S.No ┃ STATION NAME                       ┃  ARRIVAL TIME    ┃   DEPARTURE TIME   ┃\n";
            cout<<"┗━━━━━━┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┗━━━━━━━━━━━━━━━━━━┗━━━━━━━━━━━━━━━━━━━━┛\n";
            
            
             // cout<<"╔══════╦════════════════════════════════════╦══════════════════╦════════════════════╗\n";
             // cout<<"║ S.No ║ STATION NAME                       ║  ARRIVAL TIME    ║   DEPARTURE TIME   ║\n";
             // cout<<"╠══════╬════════════════════════════════════╬══════════════════╬════════════════════╣\n";
            
            printv(rarrays, trn,deprarrays,arrivalrarrays);                   //Calling print Time Table Fxn.
            printv1(arrays,trn,deparrays,arrivalarrays);                      //Calling print Time Table Fxn.
            
            cout<<"┗━━━━━━┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┗━━━━━━━━━━━━━━━━━━┗━━━━━━━━━━━━━━━━━━━━┛\n";
            cout<<"\n";
            
        }
        
        //Coach Layout //Coach Layout //Coach Layout //Coach Layout //Coach Layout //Coach Layout //Coach Layout //Coach Layout //Coach Layout //Coach Layout
        
        std::cout<<"\n\nSelect a Specific Coach for Layout (eg A,B use Variables of the Coach) ";                                                     //Coach Layout
        
        std::string strg;
        std::cin>>strg;
        
        std::string str = lc(strg);
        
        // Convert each character in the string to lowercase
        for (char &c : str) {
            c = tolower(c);
        }
        
        
        
        
        if(str=="a" || str =="A" || str=="ae" || str =="AE" || str=="ab")                                                                              //AC-2 Tier
        {
            {std::cout<<"AC Two Tier Coach\n";
                {
                    
                    std::cout<<"Enter Seat Number ";
                    std::cin>>x;
                    int su=6,sl=5,u=2,l=1,l2=3,u2=4;
                    for(int i=1;i<=54;i++)
                    {
                        l=l+6;
                        su=su+6;
                        sl=sl+6;
                        u=u+6;
                        l2=l2+6;
                        u2=u2+6;
                        if((x==su || x==6) && x<55){
                            std::cout<<"Side Upper Berth";
                            break;
                            
                        }
                        else if((x==sl || x==5) && x<55){
                            std::cout<<"Side Lower Berth";
                            break;
                        }
                        else if((x==u || x==u2 || x==2 || x==4) && x<55){
                            std::cout<<"Upper Berth";
                            break;
                        }
                        else if((x==l || x==l2 || x==1 || x==3) && x<55){
                            std::cout<<"Lower Berth";
                            break;
                        }
                        else if(x>54 || x<0){
                            std::cout<<"Invalid Seat Number";
                            break;
                        }
                    }
                }
                cout<<"\n\n\t\t  Coach Layout\n\n";
                cout<<"\t\t   Entry/Exit\n┏━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
                int su=6,sl=5,u=2,l=1,l2=3,u2=4;
                cout<<"┃   1     2         5    ┃\n";
                cout<<"┃   3     4         6    ┃\n┃                        ┃\n";
                cout<<"┃   7     8         11   ┃\n";
                cout<<"┃   9     10        12   ┃\n┃                        ┃\n";
                
                for(int i=1;i<=54;i++)
                {
                    l=l+6;
                    su=su+6;
                    sl=sl+6;
                    u=u+6;
                    l2=l2+6;
                    u2=u2+6;
                    
                    cout<<"┃   "<<l+6<<"    "<<u+6<<"   "<<"     "<<sl+6<<"   ┃"<<endl;
                    cout<<"┃   "<<l2+6<<"    "<<u2+6<<"   "<<"     "<<su+6<<"   ┃"<<endl<<"┃                        ┃"<<endl;
                    if(su+6==54)
                        break;
                }
                cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━┛\t\t\n           Entry/Exit\n\n";
            }
        }
        
        
        
        
        
        else if(str=="b" || str=="B"  || str=="be" || str =="BE" || str=="Be"){                                                               //Third AC
            
            {  std::cout<<"AC Three Tier Coach\n";
                {
                    std::cout<<"Enter Seat Number ";
                    std::cin>>x;
                    int L=1,M=2,U=3,SL=7,L2=4,M2=5,U2=6,SU=8;
                    for(int i=1;i<=72;i++)
                    {  L=L+8;
                        M=M+8;
                        U=U+8;
                        SL=SL+8;
                        SU=SU+8;
                        M2=M2+8;
                        U2=U2+8;
                        L2=L2+8;
                        if(x==SU || x==8){
                            std::cout<<"Side Upper Berth";
                            break;
                        }
                        
                        else if((x==SL || x==7) && x<73 ){
                            std::cout<<"Side Lower Berth";
                            break;
                        }
                        else if((x==U || x==U2 || x==6 || x==3) && x<73){
                            std::cout<<"Upper Berth";
                            break;
                        }
                        else if((x==L || x==L2 || x==1 || x==4) && x<73){
                            std::cout<<"Lower Berth";
                            break;
                        }
                        else if((x==M || x==M2  || x==2 || x==5)&& x<73){
                            std::cout<<"Middle Berth";
                            break;
                        }
                        else if(x>72){
                            std::cout<<"Invalid Seat Number";
                            break;
                        }
                    }
                }
                cout<<"\n\n          Coach Layout";
                cout<<"\n\n\t\t       Entry/Exit\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
                cout<<"┃   1    2    3         7    ┃\n┃   4    5    6         8    ┃\n┃                            ┃\n";
                cout<<"┃   9    10   11        15   ┃\n";
                cout<<"┃   12   13   14        16   ┃\n┃                            ┃\n";
                int L=1,M=2,U=3,SL=7,L2=4,M2=5,U2=6,SU=8;
                for(int i=1;i<=80;i++)
                {   L=L+8;
                    M=M+8;
                    U=U+8;
                    SL=SL+8;
                    SU=SU+8;
                    M2=M2+8;
                    U2=U2+8;
                    L2=L2+8;
                    
                    cout<<"┃   "<<L+8<<"   "<<M+8<<"   "<<U+8<<"        "<<SL+8<<"   ┃"<<"\n";
                    cout<<"┃   "<<L2+8<<"   "<<M2+8<<"   "<<U2+8<<"        "<<SU+8<<"   ┃\n┃                            ┃";
                    cout<<"\n";
                    if(SU+8==72){
                        break;
                    }
                }
                cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\t\t     \n               Entry/Exit\n\n";
            }
        }
        
        
        
        
        else if(str=="HCP" || str=="hcp" || str=="h" || str=="H" || str=="ha" || str=="HA" )                                                            //First ac
            
        {
            {std::cout<<"First AC Coach\n";
                {
                    {
                        std::cout<<"Enter Seat Number ";
                        std::cin>>x;
                        if(x%2==0 && x<27 && x>0){
                            std::cout<<"Upper Cabin Berth";
                        }
                        else if(x%2!=0 && x<27&& x>0){
                            std::cout<<"Lower Cabin Berth";
                        } else{
                            std::cout<<"Invalid Seat Number";
                        }
                        
                        cout<<endl;
                        cout<<"\n          Coach Layout\n\n";
                        cout<<"                  Entry/Exit\n";
                        cout<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
                        cout<<"┃   1     2                    ┃\n┃                  CABIN-A     ┃\n";
                        cout<<"┃   3     4                    ┃\n";
                        cout<<"┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n";
                        cout<<"┃   5     6                    ┃\n┃                  CABIN-B     ┃\n┃                              ┃\n";
                        cout<<"┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n";
                        cout<<"┃   7     8                    ┃\n┃                  CABIN-C     ┃\n";
                        cout<<"┃   9     10                   ┃\n";
                        cout<<"┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n";
                        cout<<"┃   11    12                   ┃\n┃                  CABIN-D     ┃\n┃                              ┃\n";
                        cout<<"┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n";
                        cout<<"┃   13    14                   ┃ \n┃                  CABIN-E     ┃\n┃                              ┃\n";
                        cout<<"┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n";
                        cout<<"┃   15    16                   ┃ \n┃                  CABIN-F     ┃\n";
                        cout<<"┃   17    18                   ┃\n";
                        cout<<"┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n";
                        cout<<"┃   19    20                   ┃\n┃                  CABIN-G     ┃\n";
                        cout<<"┃   21    22                   ┃\n";
                        cout<<"┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n";
                        cout<<"┃   23    24                   ┃\n┃                  CABIN-H     ┃\n";
                        cout<<"┃   25    26                   ┃\n";
                        cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
                        cout<<"                  Entry/Exit\n\n";
                        
                    }}}}
        
        
        
        else if(str=="d" || str=="de") {                                                                                                                //SECOND Seating
            
            { std::cout<<"Second Seating Coach\n";
                
                
                std::cout<<"Enter Seat Number ";
                std::cin>>x;
                int wndo=1, aisle=2, a1=3,mdl1=4,w1=5,a2=8,mdl2=7,w2=6;
                for(int i=1;i<=106;i++)
                {
                    a1=a1+6;
                    mdl1=mdl1+6;
                    w1=w1+6;
                    a2=a2+6;
                    mdl2=mdl2+6;
                    w2=w2+6;
                    if((x==wndo || x==w1 || x==w2 || x==5 || x==6) && x<107){
                        std::cout<<"Window Seat";
                        break;
                    }
                    else if((x==aisle || x==a1 || x==a2 || x==3 || x==8) && x<107){
                        std::cout<<"Aisle Seat";
                        break;
                    }
                    else if((x==mdl1 || x==mdl2 || x==4 ||x==7) && x<107){
                        std::cout<<"Middle Seat";
                        break;
                    }
                    else if(x>106){
                        std::cout<<"Invalid Seat Number";
                        break;
                    }
                }
                cout<<"\n            Coach Layout\n";
                {
                    int a1=3,mdl1=4,w1=5,a2=8,mdl2=7,w2=6;
                    cout<<"\n                 Entry/Exit\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
                    cout<<"┃    1     "<<"2              "<<"3     "<<"4     "<<"5    ┃\n";
                    cout<<"┃    6     "<<"7     "<<"8        "<<"9     "<<"10    "<<"11   ┃ \n";
                    
                    for(int i=1;i<=99;i++)
                    {
                        a1=a1+6;
                        mdl1=mdl1+6;
                        w1=w1+6;
                        a2=a2+6;
                        mdl2=mdl2+6;
                        w2=w2+6;
                        cout<<"┃    "<<w2<<"    "<<mdl2<<"    "<<a2<<"       "<<a1+6<<"    "<<mdl1+6<<"    "<<w1+6<<"   ┃ "<<"\n";
                        if(w1==89){
                            break;}
                    }
                    cout<<"┃    96    "<<"97    "<<"98       "<<"99    "<<"100   "<<"101  ┃ \n";
                    cout<<"┃    102   "<<"103  "<<" 104            "<<"105   "<<"106  ┃\n┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
                    cout<<"                Entry/Exit\n\n";
                    
                    {
                    }
                }
            }
        }
        
        
        
        
        else if(str=="s" || str=="se"){
            {                                                                                                                                                    //SLeeper
                std::cout<<"Sleeper Coach\n";
                {int L=1,M=2,U=3,SL=7,L2=4,M2=5,U2=6,SU=8;
                    std::cout<<"Enter Seat Number ";
                    std::cin>>x;
                    for(int i=1;i<=80;i++)
                    {  L=L+8;
                        M=M+8;
                        U=U+8;
                        SL=SL+8;
                        SU=SU+8;
                        M2=M2+8;
                        U2=U2+8;
                        L2=L2+8;
                        if(x==SU || x==8){
                            std::cout<<"Side Upper Berth";
                            break;
                        }
                        
                        else if((x==SL || x==7) && x<81 ){
                            std::cout<<"Side Lower Berth";
                            break;
                        }
                        
                        else if((x==U || x==U2 || x==6 || x==3) && x<81){
                            std::cout<<"Upper Berth";
                            break;
                        }
                        
                        else if((x==L || x==L2 || x==1 || x==4) && x<81){
                            std::cout<<"Lower Berth";
                            break;
                        }
                        
                        else if((x==M || x==M2  || x==2 || x==5)&& x<81){
                            std::cout<<"Middle Berth";
                            break;
                        }
                        
                        else if(x>80 || x<0){
                            std::cout<<"Invalid Seat Number";
                            break;
                        }}}
                cout<<"\n\n          Coach Layout";
                cout<<"\n\n\t\t       Entry/Exit\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
                cout<<"┃   1    2    3         7    ┃\n┃   4    5    6         8    ┃\n┃                            ┃\n";
                cout<<"┃   9    10   11        15   ┃\n";
                cout<<"┃   12   13   14        16   ┃\n┃                            ┃\n";
                int L=1,M=2,U=3,SL=7,L2=4,M2=5,U2=6,SU=8;
                for(int i=1;i<=80;i++)
                {   L=L+8;
                    M=M+8;
                    U=U+8;
                    SL=SL+8;
                    SU=SU+8;
                    M2=M2+8;
                    U2=U2+8;
                    L2=L2+8;
                    cout<<"┃   "<<L+8<<"   "<<M+8<<"   "<<U+8<<"        "<<SL+8<<"   ┃"<<"\n";
                    cout<<"┃   "<<L2+8<<"   "<<M2+8<<"   "<<U2+8<<"        "<<SU+8<<"   ┃\n┃                            ┃";
                    cout<<"\n";
                    if(SU+8==80){
                        break;
                    }
                }
                cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\t\t     \n               Entry/Exit\n\n";
            }
        }
        
        
        
        
        
        
        else if(str=="M" || str=="m" || str=="ME" || str=="me" || str=="Me" || str=="mE"){
            {                                                                                                                                           //3 tier Economy
                std::cout<<"AC three tier Economy Coach\n";
                {int L=1,M=2,U=3,SL=7,L2=4,M2=5,U2=6,SU=8;
                    std::cout<<"Enter Seat Number ";
                    std::cin>>x;
                    for(int i=1;i<=83;i++)
                    {  L=L+8;
                        M=M+8;
                        U=U+8;
                        SL=SL+8;
                        SU=SU+8;
                        M2=M2+8;
                        U2=U2+8;
                        L2=L2+8;
                        if(x==SU || x==8){
                            std::cout<<"Side Upper Berth";
                            break;
                        }
                        
                        else if((x==SL || x==7) && x<84 ){
                            std::cout<<"Side Lower Berth";
                            break;
                        }
                        
                        else if((x==U || x==U2 || x==6 || x==3) && x<84){
                            std::cout<<"Upper Berth";
                            break;
                        }
                        
                        else if((x==L || x==L2 || x==1 || x==4) && x<84){
                            std::cout<<"Lower Berth";
                            break;
                        }
                        
                        else if((x==M || x==M2  || x==2 || x==5)&& x<84){
                            std::cout<<"Middle Berth";
                            break;
                        }
                        
                        else if(x>83 || x<0){
                            std::cout<<"Invalid Seat Number";
                            break;
                        }}}
                
                cout<<"\n\n\t\t       Entry/Exit\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
                cout<<"┃   1    2    3         7    ┃\n┃   4    5    6         8    ┃\n┃                            ┃\n";
                cout<<"┃   9    10   11        15   ┃\n";
                cout<<"┃   12   13   14        16   ┃\n┃                            ┃\n";
                int L=1,M=2,U=3,SL=7,L2=4,M2=5,U2=6,SU=8;
                for(int i=1;i<=83;i++)
                {   L=L+8;
                    M=M+8;
                    U=U+8;
                    SL=SL+8;
                    SU=SU+8;
                    M2=M2+8;
                    U2=U2+8;
                    L2=L2+8;
                    cout<<"┃   "<<L+8<<"   "<<M+8<<"   "<<U+8<<"        "<<SL+8<<"   ┃"<<"\n";
                    cout<<"┃   "<<L2+8<<"   "<<M2+8<<"   "<<U2+8<<"        "<<SU+8<<"   ┃\n┃                            ┃";
                    cout<<"\n";
                    if(SU==72){
                        break;
                    }}
                cout<<"┃   81   82   83             ┃\n┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\t\t     \n                Entry/Exit\n\n";
            }}
        
        
        
        
        else if(str=="e" || str=="E"){
            int w1=1,w2=4,a1=2,a2=3;                                                                                                          //Executive  Chair Car
            std::cout<<"\nExecutive AC Chair Car Coach\n";
            std::cout<<"Enter Seat Number ";
            std::cin>>x;
            for(int i=1;i<=56;i++){
                w1=w1+4;
                w2=w2+4;
                a1=a1+4;
                a2=a2+4;
                if((x==1 ||x==4  || x==w1 || x==w2) && x<57){
                    std::cout<<"Window Seat";
                    break;
                }
                else if((x==2 ||x==3  || x==a1 || x==a2 ) && x<57){
                    std::cout<<"Aisle Seat";
                    break;
                }
                else if(x>56 || x<0){
                    std::cout<<"Invalid Seat Number";
                    break;
                }}
            cout<<"\n\n\t\t   Coach Layout\n\n";
            cout<<"           Entry/Exit\n";
            cout<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
            cout<<"┃   1     2          3     4    ┃\n";
            cout<<"┃   5     6          7     8    ┃\n";
            cout<<"┃   9     10         11    12   ┃\n";
            
            int w1a=1,w2a=4,a1a=2,a2a=3;
            for(int i=1;i<=56;i++){
                w1a=w1a+4;
                w2a=w2a+4;
                a1a=a1a+4;
                a2a=a2a+4;
                cout<<"┃   "<<w1a+8<<"    "<<a1a+8<< "         "<<a2a+8<<"    "<<w2a+8<<"   ┃"<<endl;
                if(w2a+8==56){
                    break;}
                
            }
            cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
            cout<<"            Entry/Exit            \n\n";
        }
        
        
        
        
        else if(str=="c" || str=="C" )                                                                                                                   //Chair Car
        {
            {
                std::cout<<"AC Chair Car Coach\n";
                std::cout<<"Enter Seat Number ";
                std::cin>>x;
                int a1=7,mdl1=8,w1=5,a2=6,w2=9;
                for(int i=1;i<=78;i++)
                {
                    a1=a1+5;
                    mdl1=mdl1+5;
                    w1=w1+5;
                    a2=a2+5;
                    w2=w2+5;
                    if((x==1 ||x==4 ||x==75 || x==78 || x==w1 || x==w2 || x==5 || x==9) && x<79){
                        std::cout<<"Window Seat";
                        break;
                    }
                    else if((x==2 ||x==3 ||x==76 ||x==77 || x==a1 || x==a2 || x==7 ) && x<79){
                        std::cout<<"Aisle Seat";
                        break;
                    }
                    else if((x==mdl1 || x==8) && x<79){
                        std::cout<<"Middle Seat";
                        break;
                    }
                    else if(x>78){
                        std::cout<<"Invalid Seat Number";
                        break;
                    }}}
            {
                cout<<"\n\n\t\t   Coach Layout\n\n";
                cout<<"             Entry/Exit              \n";
                cout<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
                cout<<"┃   1     2              3     4    ┃\n";
                cout<<"┃   5     6        7     8     9    ┃\n";
                int a1=7,mdl1=6,w1=5,a2=8,w2=9;
                for(int i=1;i<=78;i++)
                {
                    a1=a1+5;
                    mdl1=mdl1+5;
                    w1=w1+5;
                    a2=a2+5;
                    w2=w2+5;
                    
                    cout<<"┃   "<<w1<<"    "<<mdl1<<"       "<<a1<<"    "<<a2<<"    "<<w2<<"   ┃\n";
                    
                    if(w2==74){
                        break;
                    }}
                cout<<"┃   75    76             77    78   ┃\n";
                cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
                cout<<"              Entry/Exit\n\n";}}
        
        
        
        
        else if(str=="gen" || str=="GEN" || str=="GS" || str=="gs" || str=="Gen" || str=="Gs"){                                                     //GeNeral Coach
            std::cout<<"General Unreserved Coach\n";
            std::cout<<"No Seat Layout for the Selected Coach\n";
        }
        
        
        
        
        
        else if( str=="slr" || str=="SLR" ||str=="DL" || str=="dl"){                                                                                //DL Coach
            std::cout<<"Seating cum Luggage & Rake Coach\n";
            
            std::cout<<"No Seat Layout for the Selected Coach\n";
            
            
        }
        
        
        
        
        else if(str=="k" || str=="K" ){                                                                                                                //Anubhuti Coach
            int w1=1,w2=4,a1=2,a2=3;
            std::cout<<"AC Anubhuti Chair Car Coach\n";
            std::cout<<"Enter Seat Number ";
            std::cin>>x;
            for(int i=1;i<=56;i++){
                w1=w1+4;
                w2=w2+4;
                a1=a1+4;
                a2=a2+4;
                if((x==1 ||x==4  || x==w1 || x==w2) && x<57){
                    std::cout<<"Window Seat";
                    break;
                }
                else if((x==2 ||x==3  || x==a1 || x==a2 ) && x<57){
                    std::cout<<"Aisle Seat";
                    break;
                }
                else if(x>56 || x<0){
                    std::cout<<"Invalid Seat Number";
                    break;
                }
            }
            cout<<"\n\n\t\t   Coach Layout\n\n";
            cout<<"\t\t    Entry/Exit\n";
            cout<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
            cout<<"┃   1     2          3     4    ┃\n";
            cout<<"┃   5     6          7     8    ┃\n";
            cout<<"┃   9     10         11    12   ┃\n";
            
            int w1a=1,w2a=4,a1a=2,a2a=3;
            for(int i=1;i<=56;i++){
                w1a=w1a+4;
                w2a=w2a+4;
                a1a=a1a+4;
                a2a=a2a+4;
                cout<<"┃   "<<w1a+8<<"    "<<a1a+8<< "         "<<a2a+8<<"    "<<w2a+8<<"   ┃"<<endl;
                if(w2a+8==56){
                    break;}
                
            }
            cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛"<<"\n\t\t    Entry/Exit\n\n";
        }
        
        
        
        
        
        
        else if(str=="eog" ||  str=="EOG" || str=="Eog" ){                                                                                        //eog Coach
            std::cout<<"End-on Generator Car\n";
            std::cout<<"No Seat Layout for the Selected Coach\n";
        }
        
        
        
        
        
        else if(str=="G" || str=="g" || str=="GD" || str=="gd" || str=="Gd" ){
            std::cout<<"Garib Rath Three Tier Coach\n";                                                                                          //garib rath 3ac Coach
            std::cout<<"Enter Seat Number ";
            std::cin>>x;{
                int L=1,M=2,U=3,SL=7,L2=4,M2=5,U2=6,SU=9,sm=8;
                for(int i=1;i<=81;i++)
                {  L=L+9;
                    M=M+9;
                    U=U+9;
                    SL=SL+9;
                    SU=SU+9;
                    M2=M2+9;
                    U2=U2+9;
                    L2=L2+9;
                    sm=sm+9;
                    if(x==SU || x==9){
                        std::cout<<"Side Upper Berth";
                        break;
                    }
                    
                    else if((x==SL || x==7) && x<82 ){
                        std::cout<<"Side Lower Berth";
                        break;
                    }
                    else if((x==U || x==U2 || x==6 || x==3) && x<82){
                        std::cout<<"Upper Berth";
                        break;
                    }
                    else if((x==L || x==L2 || x==1 || x==4) && x<82){
                        std::cout<<"Lower Berth";
                        break;
                    }
                    else if((x==M || x==M2  || x==2 || x==5)&& x<82){
                        std::cout<<"Middle Berth";
                    }
                    else if(( x==sm  || x==8 )&& x<82){
                        std::cout<<"Middle Berth";
                        break;
                    }
                    
                    else if(x>81 || x<0){
                        std::cout<<"Invalid Seat Number";
                        break;
                    }
                }}
            {
                cout<<"\n\n\t\t\tCoach Layout\n\n";
                cout<<"\t\t\t   Entry/Exit\n┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
                cout<<"┃   1    2    3         7    ┃\n┃                       8    ┃\n";
                cout<<"┃   4    5    6         9    ┃\n|                            ┃\n";
                int L=1,M=2,U=3,SL=7,L2=4,M2=5,U2=6,SU=9,sm=8;
                for(int i=1;i<=81;i++)
                {  L=L+9;
                    M=M+9;
                    U=U+9;
                    SL=SL+9;
                    SU=SU+9;
                    M2=M2+9;
                    U2=U2+9;
                    L2=L2+9;
                    sm=sm+9;
                    cout<<"┃   "<<L<<"   "<<M<<"   "<<U<<"        "<<SL<<"   ┃\n";
                    cout<<"┃                       "<<sm<<"   ┃"<<endl;
                    cout<<"┃   "<<L2<<"   "<<M2<<"   "<<U2<<"        "<<SU<<"   ┃\n┃                            ┃\n";
                    if(SU==81){
                        break;
                    }}
                    cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\t\t\t    Entry/Exit\n\n";
            }
        }
        
        
            else if(str=="RMS" || str=="rms"){                                                                                                //MAIL SERVICE
            std::cout<<"Railway Mail Service Coach \n";
            std::cout<<"No Seat Layout for the Selected Coach\n";//rms
        }
        
        
        else if(str=="J" || str=="j"){                                                                                                        //garib rath chair car
            
            std::cout<<"\nGarib Rath AC Chair Car \n";
            std::cout<<"Enter Seat Number ";
            std::cin>>x;
            {
                int w1=1,m1=2,a1=3;
                int w2=6,m2=5,a2=4;
                for(int i=1;i<=102;i++){
                    w1=w1+6;
                    w2=w2+6;
                    a1=a1+6;
                    a2=a2+6;
                    m1=m1+6;
                    m2=m2+6;
                    
                    if(( x==w1 || x==w2 || x==1 || x==6 ) && x<103){
                        std::cout<<"Window Seat";
                        break;
                    }
                    else if((x==3 || x==a1 || x==a2 || x==4 ||x==9 ||x==10) && x<103){
                        std::cout<<"Aisle Seat";
                        break;
                    }
                    else if((x==m1 || x==m2 || x==2 ||x==5 || x==8 || x==11 ) && x<103){
                        std::cout<<"Middle Seat";
                        break;
                    }
                    else if(x>102 || x<0){
                        std::cout<<"Invalid Seat Number";
                        break;
                    }}}
            {
                cout<<"\n\n\t\t\t   Coach Layout\n\n";
                cout<<"\t\t\t    Entry/Exit\n";
                cout<<"┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
                cout<<"┃   1     2     3        4     5      6    ┃\n";
                cout<<"┃   7     8     9        10    11     12   ┃\n";
                int w1=1,m1=2,a1=3;
                int w2=6,m2=5,a2=4;
                for(int i=1;i<=102;i++){
                    w1=w1+6;
                    w2=w2+6;
                    a1=a1+6;
                    a2=a2+6;
                    m1=m1+6;
                    m2=m2+6;
                    
                    cout<<"┃   "<<w1+6<<"    "<<m1+6<<"    "<<a1+6<<"       "<<a2+6<<"    "<<m2+6<<"     "<<w2+6<<"   ┃"<<"\n";
                    
                    if(w2+6==96){
                        break;
                    }
                } cout<<"┃   97    98    99       100   101    102  ┃\n";
                  cout<<"┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n\t\t\t    Entry/Exit\n\n";}}
        
        
        
        
        
            else if(str=="PC" || str=="Pc" || str=="pc" ){                                                                                            //pantry car Coach
            std::cout<<"Pantry Car\n";
            std::cout<<"No Seat Layout for the Selected Coach\n";
        }
        
        else{
            std::cout<<"No Coach Layout for this Coach Number\n";}
    
    
    
        std::cout<<"\n\n";
        return main();
    }















































