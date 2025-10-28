def solution(chicken):
    chicken_to_order = chicken // 10
    n_of_coupons = (chicken % 10) + (chicken // 10)
    
    while n_of_coupons >= 10:
        chickens = n_of_coupons // 10
        chicken_to_order += n_of_coupons // 10
        n_of_coupons %= 10
        n_of_coupons += chickens
        
        
    return chicken_to_order
    