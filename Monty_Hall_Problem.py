import random
from matplotlib import pyplot as plt

switched_result_list=[] # 선택을 바꿨을때의 결과 값들을 저장할 리스트
not_switched_result_list =[] # 선택을 유지했을때의 결과 값들을 저장할 리스트

# 특정 횟수에서의 선택에 따른 결과 값들을 저장
switched = 0 
not_switched = 0

for i in range(1,1000):
	for j in range(1,i):
		doors = ["Car","Goat","Goat"] # 참가자가 선택할 문 3개
		
		random.shuffle(doors) # 무작위 선택을 위해 리스트를 랜덤하게 섞음
		#print(doors)

		select = doors.pop(0) # 참가자가 하나를 선택

		count=0
		for k in doors: # 남은 문들 중 염소가 있는 문 하나를 제거(오픈)
			if(k=="Goat"):
				doors.pop(count)
				break
			count+=1

		left = doors.pop() # 사용자가 선택한 문, 염소가 있는 문을 제거하고 남은 문

		#print(select)
		#print(left)

		if(select == "Car"): # 첫 선택을 유지 했을 때, 차를 고른 경우
			not_switched+=1
		elif(left == "Car"): # 선택을 바꾸었을 때, 차를 고른 경우
			switched+=1

	switched_result_list.append(switched)
	not_switched_result_list.append(not_switched)
	
	switched = 0
	not_switched = 0

x = range(1,1000)

print(len(not_switched_result_list))

y1 = switched_result_list
y2 = not_switched_result_list

plt.plot(x,y1,'r',label='switched')
plt.plot(x,y2,'b',label='not switched')
plt.xlabel('The number of trials')
plt.ylabel('The number of getting a car ')
plt.title('Monty Hall')
plt.legend(loc='upper right')
plt.show()