from flask import Flask, render_template, request, redirect, url_for,flash, jsonify, send_file
from flask import session
from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField, SelectField,EmailField
from wtforms.validators import DataRequired, Email, Length, Regexp
from flask_wtf.csrf import CSRFProtect

import re
import requests
from bs4 import BeautifulSoup
from datetime import datetime,timedelta
import mysql.connector

import os
import io

from gtts import gTTS
import pandas as pd
import pygame
from pygame import mixer

import csv
import random
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt


db_connection = mysql.connector.connect(
    host='localhost',
    user='root',
    password='750Eight_',
    database='stations_db'
)


app = Flask(__name__)
app.secret_key = '_seven808289' 
csrf = CSRFProtect(app)





user_agents = [
    "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
    "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
    "Mozilla/5.0 (X11; Linux x86_64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/120.0.0.0 Safari/537.36",
]





dates_dict = {
    'today': datetime.now().strftime("%Y-%m-%d"),
    'yesterday': (datetime.now() - timedelta(days=1)).strftime("%Y-%m-%d"),
    'tomorrow': (datetime.now() + timedelta(days=1)).strftime("%Y-%m-%d")
}





class CoachForm(FlaskForm):
    train_number = StringField(" ", validators=[DataRequired()], render_kw={"placeholder": "Get Coach Position"})
   
    from_stn = StringField(" ", validators=[DataRequired()], render_kw={"placeholder": "Boarding From"})
    to_stn = StringField(" ", validators=[DataRequired()], render_kw={"placeholder": "Boarding To"})
    
    selected_date = SelectField('', choices=[(key, value) for key, value in dates_dict.items()])
    
    train_no = StringField(" ", validators=[DataRequired()], render_kw={"placeholder": "Get Time Table"})
    train_n = StringField(" ", validators=[DataRequired()], render_kw={"placeholder": "Get Running Status"})
    train_num = StringField(" ", validators=[DataRequired()], render_kw={"placeholder": "Get Announcement"})    
    train_fact = StringField(" ", validators=[DataRequired()], render_kw={"placeholder": "Get Train Name Facts"})    
    
    selected_lang = SelectField('', choices=["Hindi","English","Punjabi"])

    
    submit = SubmitField("Search")
    
    




def get_train_name(train_n):
    
    url1 = f'https://runningstatus.in/status/{train_n}'
   
    response1 = requests.get(url1)

    soup1 = BeautifulSoup(response1.text, 'html.parser')
    h1_elem = soup1.find('h1', style='font-size:16px;font-weight:bold;color:#4266b2;')

    title= h1_elem.get_text(strip=True)
    
    if "Live" in title:
        parts = title.split("Live", 1)  
        return parts[0].strip()  
    
    return title
    
    
    


@app.route('/', methods=['GET', 'POST'])
def index():
    
    form = CoachForm()

    
    if form.validate_on_submit():
        session['train_number'] = form.train_number.data
        return redirect(url_for("show_coach_position1"))
        
    if form.validate_on_submit():
        session['from_stn'] = form.from_stn.data
        session['to_stn'] = form.to_stn.data
        return redirect(url_for("trains_bw_stations1"))
    
    
    
    
    def draw_colored_bar(length_percentage, color1='#8EF4F3', color2='#666687'):
        fig, ax = plt.subplots()
        full_length = 1.0  
        length1 = length_percentage / 100.0 
        length2 = full_length - length1 

        ax.barh(0, length1, color=color1, edgecolor='none', height=0.2) 
        ax.barh(0, length2, left=length1, color=color2, edgecolor='none', height=0.2)
    
        ax.set_xlim(0, 1)
        ax.set_ylim(-0.5, 0.5)
        ax.grid(False)
    
        for spine in ax.spines.values():
            spine.set_visible(False)
    
        ax.get_yaxis().set_visible(False)
        ax.get_xaxis().set_ticks([])
    
        static_folder = 'static'
        if not os.path.exists(static_folder):
            os.makedirs(static_folder)  
    
        file_path = os.path.join(static_folder, 'bar_plot.png')
    
        if os.path.exists(file_path):
            os.remove(file_path)
    
        plt.savefig(file_path, bbox_inches='tight') 
    
    x = random.randint(30, 70)
    y=100-x

    if x>y:
        draw_colored_bar(y, color1='blue', color2='lightgray')
        txt = f"{x}% trains are running on-time."
    else:
        draw_colored_bar(x, color1='blue', color2='lightgray')
        txt = f"{y}% trains are running on-time." 
    
    return render_template("home_page.html", form=form,txt=txt)



def extract_content(input_string):
    start_pattern = "&l;p&g;&l;b&g;"
    end_pattern = "&l;/b&g;&q;,&q;"
    
    start_pos = input_string.find(start_pattern)
    end_pos = input_string.find(end_pattern)  
  
    if start_pos != -1 and end_pos != -1:
        start_pos += len(start_pattern)
        new_string=str(input_string[start_pos:end_pos])
        return new_string.title()




@app.route('/train-coach-position',methods=['GET', 'POST'])
def show_coach_position():  
    form = CoachForm()
    if form.validate_on_submit():
        session['train_number'] = form.train_number.data
        return redirect(url_for("show_coach_position"))
    
    train_number = request.form.get('train_number','22222')
    
    
    url = f'https://www.railofy.com/train-coach-position/{train_number}/'
    response = requests.get(url)
    soup = BeautifulSoup(response.content, 'html.parser')
    
    descrip = soup.find_all('div', class_='train_det_coach_box_desktop_train_det_coach_ele_box__tqqDP')
    description=["Engine"]
    
    # (enginee,<- b2, b1, pc....)
    
  
    for item in descrip:
        description.append(item.text.strip())
        
    description=" ↤ ".join(description)
    title=get_train_name(train_number)
    name=title
        
        
    url1 = f"https://www.confirmtkt.com/train-schedule/{train_number}"
    response1 = requests.get(url1)
    soup1 = BeautifulSoup(response1.content, 'html.parser')
    
    composition_elem = soup1.find('p')
    composition=str(composition_elem)
    
    composition = re.sub(r'<.*?>', '', composition)
    
    # re.sub(r'<.*?>', '', composition)
       
    train_info ={"title": title,"description": description,"composition":composition,"name":name}
    
    return render_template("coach_position1.html",train_info=train_info,form=form)





def get_station_name(station_code):
    station_code=station_code.upper()
    cursor = db_connection.cursor()
    
    query = "SELECT station_name FROM stations WHERE station_code =%s;" 
    cursor.execute(query, (station_code,))
    result = cursor.fetchone()
    
    
    cursor.fetchall()
    cursor.close()
    
    if not result:
        return station_code
    else:
        return result

@app.route('/train-bw-stations',methods=['GET', 'POST'])
def trains_bw_stations():
    form = CoachForm()
    if form.validate_on_submit():
        try:
            session['from_stn'] = form.from_stn.data
            session['to_stn'] = form.to_stn.data        
            return redirect(url_for("trains_bw_stns"))
        except Exception:
            "Try Looking from ALternate Stations"
                  
    from_stn = request.form.get('from_stn',"MMCT")
    to_stn = request.form.get('to_stn',"NDLS")
                
    url = "https://www.railmitra.com/trains-between-stations/"+from_stn+"/"+to_stn
    headers = {'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'}
   
    response = requests.get(url, headers=headers)
    response.raise_for_status() 
   
    soup = BeautifulSoup(response.content, 'html.parser')
    data = soup.find_all('span', style='color:#000;')
             
    data=str(data)
    data=data.replace("["," ")

    data = re.sub(r'<.*?>', '', data)
    data=data.split(",")
     
    new_data=[]
    for x in range(len(data)):
        if x%2==0:   
            new_data.append(data[x])
        

            
    time_taken=soup.find_all("div",class_="col-md-6 text-center")
    time_taken=str(time_taken)
    
    
    time_taken=time_taken.replace("[","").replace("]","") 
    time_taken=re.sub(r'<.*?>', '',time_taken)   
    time_taken=time_taken.replace(" hr\nn/a", "")
    time_taken=time_taken.replace(".",":")
    time_taken=time_taken.split(",")
    time_taken = [time.strip(" ") for time in time_taken] 
    
    try: 
        temp = [int(time.split(':')[0]) for time in time_taken]
        mint=min(temp)
        maxt=max(temp)
        avgt=sum(temp)//len(temp)
        total=len(time_taken)
        min_index = temp.index(mint)
        max_index = temp.index(maxt)
        min_train=new_data[min_index]
        max_train=new_data[max_index] 
    except (ZeroDivisionError,ValueError,IndexError):
        temp=int(1)
        total=0
        mint=0
        maxt=0
        avgt=0
        min_train=0
        max_train=0   

    frm_station=get_station_name(from_stn)
    frm_station=str(frm_station)
    frm_station=re.sub(r'[^\w\s]', '', frm_station)
    
    to_station=get_station_name(to_stn)
    to_station=str(to_station)
    to_station=re.sub(r'[^\w\s]', '', to_station)       

    froms=soup.find_all("div",class_="col-md-3")
    froms=str(froms)
    froms=froms.replace("[","")
    froms = re.sub(r'<.*?>', '', froms)
    froms=froms.replace(" ()"," | ") 
    froms=froms.split(",")
    froms=list(froms)
    from_one=[]
    to_one=[]
    for x in range(len(froms)):
        froms[x]=froms[x]+" "
        if x%2==0:
            from_one.append(froms[x])
        else:
            to_one.append(froms[x])
                    
        
    return render_template("train_bw_stn.html",new_data=new_data,time_taken=time_taken,form=form,total=total,
                           frm_station=frm_station,to_station=to_station,from_one=from_one,to_one=to_one
                           ,mint=mint,maxt=maxt,avgt=avgt,min_train=min_train,max_train=max_train)
    
    
    




@app.route('/train-time-table',methods=['GET', 'POST'])
def trains_tt():
    form = CoachForm()
    if form.validate_on_submit():
        try:
            session['train_no'] = form.train_no.data
            return redirect(url_for("trains_tt"))
        except Exception as e :
            return " "
        
    train_no = request.form.get('train_no',"22222")   
    url="https://www.trainman.in/train/"+train_no   
    
    
    
    try:
        title=get_train_name(train_no)
        name=title
    except(Exception):
        title=" "
        name=" "
        
        
    url="https://www.confirmtkt.com/train-schedule/"+train_no   


    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    
    table = soup.find('table')
    #table = soup.find("div",class_="trainstopage_timeline_listing___s1lT MuiBox-root css-0")
    if not table:
        headers=[]
        data=[]
    else:
        rows = table.find_all('tr')
        header_row = rows[0]
        data_rows = rows[1:][:-1]
        headers = []
        for header in header_row.find_all('th'):
            headers.append(header.get_text(strip=True))

        data = []
        for row in data_rows:
            data.append(list(map(lambda cell: cell.get_text(), row.find_all('td'))))    
            
             
    if title is None:
        title="No Data Found, check the train number."
        data=[]
        headers=[]
        name=" " 
        
    return render_template("train_tt.html",form=form,headers=headers,data=data,name=name,train_no=train_no)












def run_until_int(s):
    result = []
    for char in s:
        if char.isdigit():
            break
        result.append(char)
    return ''.join(result)

@app.route('/live-status',methods=['GET', 'POST'])
def live_status():

    form = CoachForm()

    if form.validate_on_submit():
        session['train_n'] = form.train_n.data
        session['selected_date'] = form.selected_date.data
        
        return redirect(url_for("live_status"))
    
    
    trains_arr=["22222","12904","19038","12919","12609"]
    n = request.args.get('n')
    
    n = str(n)
    if n == "None" or n == "":  # Check if n is "None" or an empty strin
        n = 0
    else:
        n = int(n)  # Convert n back to an integer if it's not None
    
    
    train_n = request.form.get('train_n',trains_arr[n]) 
    selected_date = request.form.get('selected_date',"today")
    
     
    title=get_train_name(train_n)
    
    
    date_reqd=dates_dict[selected_date]
   
    
    date_reqd=str(date_reqd)
    date_reqd=date_reqd.replace("-","")
    print(date_reqd)
   
    url="https://runningstatus.in/status/"+train_n+"-on-"+date_reqd
      
    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
  
    table = soup.find('table')
   
    if table:
        rows = table.find_all('tr')
        header_row = rows[0]
        data_rows = rows[1:]

        headers = []
        for header in header_row.find_all('th'):
            headers.append(header.get_text(strip=True))
        
        data=[]
        for row in data_rows[1:]:
            columns = row.find_all('td')
            if len(columns) >= 4:
                station = str(columns[0].text.strip())
                station=run_until_int(station)
            
            
                arrival = str(columns[1].text.strip())
                departure = str(columns[2].text.strip())
                platform = columns[3].text.strip()
            
                entry = [ str(station), str(arrival[0:17]), str(arrival[17:]), str(departure[0:17]),str(departure[17:]),str(platform)]
                data.append(entry)
        

        live_pos = soup.find("div",class_="card-header")  
        live_pos=str(live_pos)
        live_pos = re.sub(r'<.*?>', '', live_pos)
        temp="Reached its Destination"
        pattern = r'is(.*?)'
    
        if temp in live_pos:
            live_pos="Train Reached its Destination"
        else:
            parts = re.split(r'Status| \|', live_pos)
            live_pos=parts[1].strip()
            
    else:
        data=[]
        headers=[]
        title=''
        name=''
        live_pos="No data found, check the train number."
        
    name=title
            
   
    return render_template("live_status.html",form=form,headers=headers,data=data,name=name,train_n=train_n,live_pos=live_pos,n=n)




# string " 2 mins "
def extract_int(value):
    match = re.search(r'\d+', str(value))
    return int(match.group()) if match else None

# amritsar (asr)
def remove_parentheses(text):
    return re.sub(r'\([^)]*\)', '', text).strip()

# 12906  1   2    9  0    6 
def format_train_number(train_number):
    return '     '.join(str(train_number))
        
# stations: jn &  4
def extract_via_stations(data):
    via_Stn = []
    for row in data[1:]:
        try:
            if 'jn' in row[0].lower() and extract_int(row[2])>4:
                via_Stn.append(row[0])
        except (IndexError, TypeError):
            continue  # Skip rows that don't have enough elements or invalid data types
    return via_Stn






# string="hi this" (lnANg hi en pa)
def generate_speech(text, language, filename):
        tts = gTTS(text=text, lang=language, slow=False)
        tts.save(filename)
        print(f"Audio saved as {filename}")



def train_data(train_number,lang):
    file_path =  f"static/{train_number}.mp3"

    if os.path.isfile(file_path):
        os.remove(file_path)
        print(f"{file_path} has been deleted.")

    train_name=get_train_name(train_number)
    
    # asr csmt exp      ddn shatbadi 
    words = train_name.split(" ")
    updated_words = [   get_station_name(each)[0] if isinstance(get_station_name(each), tuple) else get_station_name(each)
        for each in words
    ]
    
    # updated_words [ dehradun shtbdi]
    train_name = " ".join(updated_words)

    replacements = {
        "JN.": " ",  
        "T.": "TERMINUS",
        "RAJ": "RAJDHANI",
        "SHTBDI": "शताब्दी",
        "SPL": "SPECIAL",
        "SF": "SUPER FAST",
        "DURONTO": "दुरोंतो",
        "KRNTI": "क्रांति",
        "JANSHATABDI": "Jan Shatabadi",
        "M": "MAIL",
        "SHTBDI" :" SHATABADI",
        "CANT": "KENT",
        "ITARSI": "ITTAARSI",
        "PT": "PANDIT",
        }

    words = train_name.split(" ")
    
    final_words = [replacements.get(word.upper(), word) for word in words]
    # updated_words [ dehradun shatabadi]
    train_name = " ".join(final_words)

    
    
    
    
    url = "https://www.railyatri.in/time-table/"+train_number

    response = requests.get(url)
    soup = BeautifulSoup(response.text, 'html.parser')
    table = soup.find('table')
    rows = table.find_all('tr')
    header_row = rows[0] 
    data_rows = rows[1:] 

    headers = []
    for header in header_row.find_all('th'):
        headers.append(header.get_text(strip=True))

    data = []
    for row in data_rows:
        data.append(list(map(lambda cell: cell.get_text(strip=True), row.find_all('td'))))

    via_stn=[]
    
    via_st=extract_via_stations(data)
    
    for each in via_st:
        via_stn.append(remove_parentheses(each).replace("jn",""))

    from_stn=remove_parentheses(data[0][0].replace("jn"," Junction "))
    to_stn=remove_parentheses(data[-1][0].replace("jn"," Junction "))


    temp_trn=format_train_number(train_number)
    
    

    english_text = f"""For your kind, information please: Train number : {temp_trn}:
    from {from_stn} to {to_stn}: via  {(via_stn[0:])}: {train_name[7:]}:
    will depart at its :scheduled time: at {data[0][3][:2]} hours: {data[0][3][3:]} minutes from: Platform Number: {data[0][4]}. Thanks."""
                    


    hindi_text = f"""यात्रीगण कृपया ध्यान दें: {from_stn} से चलकर :{(via_stn[0:])}: के रस्ते {to_stn} को जाने वाली: गाड़ी संख्या 
                :{temp_trn}: :{train_name[7:]}:      
                अपने: निर्धारित समय: {data[0][3][:2]} :बजकर: {data[0][3][3:]}: मिनट पर :प्लेटफार्म क्रमांक :{data[0][4]} से जायेगी।: धन्यवाद"""
                
                
    punj_text = f"""ਯਾਤਰੀਆਂ ਕਿਰਪਾ ਕਰਕੇ ਧਿਆਨ ਦੇਣ: {from_stn} ਤੋਂ ਚਲ ਕੇ :{(via_stn[0:])}: ਦੇ ਰਸਤੇ {to_stn} ਨੂੰ ਜਾਣ ਵਾਲੀ: ਗੱਡੀ ਸੰਖਿਆ          
                :{temp_trn}: :{train_name[7:]}:              
                ਆਪਣੇ: ਨਿਰਧਾਰਿਤ ਸੰਮੇ: {data[0][3][:2]} :  ਵਜ ਕਰ :{data[0][3][3:]}:  ਮਿੰਟ : 'ਤੇ :ਪਲੇਟਫਾਰਮ ਨੰਬਰ :{data[0][4]} ਤੋਂ ਜਾਏਗੀ। ਧੰਨਵਾਦ"""
        
                
    file_name=f"static/{train_number}.mp3" 
                
    if lang=="Hindi":
        generate_speech(hindi_text, "hi",file_name)
        
    if lang=="English":
        generate_speech(english_text, "en",file_name)
        
    if lang=="Punjabi":
        generate_speech(punj_text, "pa",file_name)
           
    return file_name
    


        
        




@app.route('/announcement',methods=['GET', 'POST'])
def announcement():
    
    form = CoachForm()
    if form.validate_on_submit():
        session['train_num'] = form.train_num.data
        session['selected_lang'] = form.selected_lang.data
        
        return redirect(url_for("announcement"))
    
    
    train_number = request.form.get('train_num','22222')
    lang = request.form.get('selected_lang',"Hindi")
    
    res=train_data(train_number,lang)
    train_name=get_train_name(train_number)
    
    return render_template("announcement.html",train_data=train_data,form=form,train_name=train_name,train_number=train_number,res=res)





def print_surrounding_lines(text):
    lines_above = []
    lines_between = []
    lines_below = []
    
    lines = text.split('\n')
    length = len(lines)
    index = 0

    while index < length:
        line = lines[index].strip()

        if line and line[0].isdigit():
           
            if index - 1 >= 0:
                lines_above.append(lines[index - 1].strip())
                    
                line=line.replace(",", "<br>"  )
                lines_between.append(line)
            
            if index + 1 < length:
                lines_below.append(lines[index + 1].strip())
                if line[0]==" ":
                    lines_below.append(lines[index + 2].strip())

        index += 1
         
    return lines_above, lines_between, lines_below


with open('/Users/madhavsharma/Documents/flask_proj/static/trains_facts.txt', encoding='utf-16', errors='ignore') as file:
    lines = file.read()

lines_above, lines_between, lines_below = print_surrounding_lines(lines)
num_lines = min(len(lines_above), len(lines_between), len(lines_below))

   
data = []
for i in range(num_lines):
    data.append({
        'above': lines_above[i],
        'between': lines_between[i],
        'below': lines_below[i]})

 
 
 
 
 
 
@app.route('/facts',methods=['GET', 'POST'])
def facts():
    form = CoachForm()
    if form.validate_on_submit():
        session['train_fact'] = form.train_fact.data
        return redirect(url_for("factss"))
    
        
    selected_indices = random.sample(range(10,200), 20)
    rand_data = []
    for i in selected_indices:
        rand_data.append({
             'rand_above': lines_above[i],
             'rand_between': lines_between[i],
             'rand_below': lines_below[i]
            })
        
    return render_template("facts.html",form=form,rand_data=rand_data)
        





@app.route('/factss',methods=['GET', 'POST'])
def factss():
    form = CoachForm()
    if form.validate_on_submit():
        session['train_fact'] = form.train_fact
        return redirect(url_for("factss"))
    
    train_no = request.form.get('train_fact')
    
    searched_data=[]
    for values in lines_between:
        try:
            if train_no in values and len(train_no) == 5:
                index=lines_between.index(values)
                searched_data.append({
                      'searched_above': lines_above[index],
                     'searched_between': lines_between[index],
                      'searched_below': lines_below[index]
                })
                break
            
        except Exception:
            index = None
            searched_data.append({
                      'searched_above': "No Trains Found",
                      'searched_between': "Try alternative train numbers.",
                      'searched_below': " " })
    
    
    return render_template("factss.html",form=form, searched_data=searched_data,train_no=train_no)










@app.route('/fare',methods=['GET', 'POST'])
def fare():
    form = CoachForm()
    return render_template("fare.html",form=form)



if __name__ == '__main__':
    app.run(debug=True)





