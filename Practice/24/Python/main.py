import json
with open('in.json','r') as f:
    data=json.load(f)
task_completed={}
for i in data:
    if i["completed"]:
        try:
            task_completed[i["userId"]]+=1
        except KeyError:
            task_completed[i["userId"]]=1
out=[]
for key,value in task_completed.items():
    out.append({"userID":key, "task_completed":value})
with open('out.json','w') as f:
    json.dump(out,f,indent=4)
    