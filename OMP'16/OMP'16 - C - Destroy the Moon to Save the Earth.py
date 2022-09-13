cases = int(input())

CONST_DIST = 1000 * 1000
CONST_TIME = 60 * 60 * 24

for k in range(cases):
    nums = input().split(' ')
    t = int(nums[0])
    s = int(nums[1])
    d = int(nums[2])

    t = t * CONST_TIME # to seconds
    d = d * CONST_DIST # to milimeters

    x1 = s * t # final position
    s1 = (x1 + d) / t # expected speed

    result = int(s1 - s)

    if result > 0:
        print('Remove', abs(result), 'tons')
    else:
        print('Add', abs(result), 'tons')