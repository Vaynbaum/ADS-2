// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
  int count = 0;
    for (int i = 0; i < len-1; i++) {
        for (int j = i+1; j < len; j++) {
            if (arr[i] + arr[j] == value)
                count++;
        }
    }
    return count;
}

int countPairs2(int *arr, int len, int value) {
  int count = 0, left = 0, right = len - 1;
    while (left < right - 1) {
        int middle = (left + right) / 2;
        if (arr[middle] <= value)
            left = middle;
        else
            right = middle;
    }
    len = right-1;

    for (int i = len; i >=0; i--) {
        for (int j = 0; j < i; j++) {
            if (arr[i] + arr[j] == value)
                count++;
            if (arr[i] + arr[j] > value)
                break;
        }
    }
    return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0, left = 0, right = len - 1;
    while (left < right - 1) {
        int middle = (left + right) / 2;
        if (arr[middle] <= value)
            left = middle;
        else
            right = middle;
    }
    len = right - 1;

    for (int i = 0; i <len; i++) {
        left = i+1, right = len-1;
        int countNum = 0;

        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid] < (value-arr[i]))
                left = mid + 1;
            else
                right = mid;
        }

        while (arr[left] == (value - arr[i])) {
            countNum++;
            left++;
        }
        count += countNum;
    }
    return count;
}
