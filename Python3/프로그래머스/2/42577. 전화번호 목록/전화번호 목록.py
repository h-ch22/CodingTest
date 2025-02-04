def solution(phone_book):
    phone_map = {}
    
    # map에 삽입 
    for phone in phone_book: 
        phone_map[phone] = 1 
    
    # phone_book 리스트 순회
    for phone in phone_book: 
        arr = "" 
        
        # string에 전화번호 삽입
        for num in phone: 
            arr += num
            
            # 현재 번호와 같지 않고 map 안에 있으면 False return
            if arr in phone_map and arr != phone:       
                return False 
                
    return True