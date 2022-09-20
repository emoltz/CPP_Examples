int countZeros(int nums[], int len, int startIdx){
    if (startIdx == len){
        return 0;
    }
    if (nums[startIdx] == 0){
        return countZeros(nums, len, startIdx + 1) + 1;
    }
    else{
        return countZeros(nums, len, startIdx + 1);
    }
}


int maxZeroLength(int nums[], int len, int startIdx){
    int temp = 0, result = 0;
    while (startIdx < len) {
        if (nums[startIdx] == 0){
            temp++;
            startIdx++;
        }
        else{
            if (temp > result){
                result = temp;
            }
            temp = 0;
            startIdx++;
        }
    }
    if (temp > result){
        result = temp;
    }
    return result;
}

int maxZeroLengthRecursive(int nums[], int len, int startIdx){
    if (len == startIdx){
        return 0;
    }
    int temp1 = 0, temp2 = 0;
    if (nums[startIdx] == 0){
        temp1 = maxZeroLengthRecursive(nums, len, startIdx + 1) + 1;
    }
    else{
        temp2 = maxZeroLengthRecursive(nums, len, startIdx + 1);
    }
    return max(temp1, temp2);
}