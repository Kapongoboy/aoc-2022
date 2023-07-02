use std::fs;

fn solution() -> i32 {
    let mut bag: Vec<i32> = Vec::new();
    let mut total: Vec<i32> = Vec::new();
    let contents = fs::read_to_string("./input.txt").
        expect("Should have been able to read the file");
    let contents = contents.lines();
    for item in contents {
        if item != "" {
            bag.push(item.parse::<i32>().unwrap());
        } else {
            total.push(bag.iter().sum());
            bag.clear();
        }
    }
    return *total.iter().max().unwrap();

}

fn main() {
    let result = solution();
    println!("the solution was {}", result);
}
