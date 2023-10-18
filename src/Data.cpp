#include "Banco.hpp"

Data::Data(){
    this->data = new tm();
}

Data::Data(int dia, int mes, int ano){
    this->data = new tm();
    this->data->tm_mday = dia;
    this->data->tm_mon = mes;
    this->data->tm_year = ano;

    mktime(this->data);
}

tm* Data::getData(){
    return this->data;
}

void Data::setData(int dia, int mes, int ano){
    this->data->tm_mday = dia;
    this->data->tm_mon = mes;
    this->data->tm_year = ano;

    mktime(this->data);
}

string Data::toString(){
    string data = "";

    if(this->data->tm_mday < 10)
        data += "0";
    
    data += to_string(this->data->tm_mday) + "/";
    
    if(this->data->tm_mon < 10)
        data += "0";
    
    data += to_string(this->data->tm_mon) + "/" + to_string(this->data->tm_year);

    return data;
}

Data Data::dataAtual(){
    time_t now = time(0);

    tm* ltm = localtime(&now);
    
    Data data(ltm->tm_mday, ltm->tm_mon, ltm->tm_year);

    return data;
}

bool Data::operator<(Data* data){
    tm* dh = data->getData();

    if(this->data->tm_year < dh->tm_year){
        return true;
    }else if(this->data->tm_year == dh->tm_year){
        if(this->data->tm_mon < dh->tm_mon){
            return true;
        }else if(this->data->tm_mon == dh->tm_mon){
            if(this->data->tm_mday < dh->tm_mday){
                return true;
            }
        }
    }

    return false;
}

bool Data::operator<=(Data* data){
    tm* dh = data->getData();

    if(this->data->tm_year <= dh->tm_year){
        if(this->data->tm_mon <= dh->tm_mon){
            if(this->data->tm_mday <= dh->tm_mday){
                return true;
            }
        }
    }

    return false;
}

bool Data::operator==(Data* data){
    tm* dh = data->getData();

    if(this->data->tm_year == dh->tm_year){
        if(this->data->tm_mon == dh->tm_mon){
            if(this->data->tm_mday == dh->tm_mday){
                return true;
            }
        }
    }

    return false;
}

bool Data::operator>(Data* data){
    tm* dh = data->getData();

    if(this->data->tm_year > dh->tm_year){
        return true;
    }else if(this->data->tm_year == dh->tm_year){
        if(this->data->tm_mon > dh->tm_mon){
            return true;
        }else if(this->data->tm_mon == dh->tm_mon){
            if(this->data->tm_mday > dh->tm_mday){
                return true;
            }
        }
    }

    return false;
}

bool Data::operator>=(Data* data){
    tm* dh = data->getData();

    if(this->data->tm_year >= dh->tm_year){
        if(this->data->tm_mon >= dh->tm_mon){
            if(this->data->tm_mday >= dh->tm_mday){
                return true;
            }
        }
    }

    return false;
}

void Data::operator=(Data* data){
    tm* dh = data->getData();

    this->data->tm_year = dh->tm_year;
    this->data->tm_mon = dh->tm_mon;
    this->data->tm_mday = dh->tm_mday;
}