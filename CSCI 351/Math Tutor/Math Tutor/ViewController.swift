//
//  ViewController.swift
//  Math Tutor
//
//  Created by Sean Tesch on 11/6/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit

class ViewController: UIViewController, UITextFieldDelegate {
    @IBOutlet weak var nameField: UITextField!
    @IBOutlet weak var titleLabel: UILabel!
    @IBOutlet weak var name: UILabel!
    @IBOutlet weak var saveButtonOutlet: UIButton!
    @IBOutlet weak var problem: UILabel!
    @IBOutlet weak var answerField: UITextField!
    @IBOutlet weak var questionMark: UILabel!
    @IBOutlet weak var answerButtonOutlet: UIButton!
    @IBOutlet weak var rightOrWrong: UILabel!
    @IBOutlet weak var streak: UILabel!
    @IBOutlet weak var anotherButtonOutlet: UIButton!
    
    var num1: Int = 0
    var num2: Int = 0
    var inputAnswer: Int = 0
    var correct: Int = 0
    
    @IBAction func saveName(sender: AnyObject) {
        let defaults = NSUserDefaults.standardUserDefaults()
        defaults.setObject(nameField.text!, forKey: "theName")
        
        titleLabel.text = "Math Tutor - Good Luck, " + nameField.text!
        titleLabel.hidden = false
        problem.hidden = false
        
        num1 = Int(arc4random_uniform(10))
        num2 = Int(arc4random_uniform(10))
        
        problem.text = "\(num1) X \(num2)"
        answerField.hidden = false
        
        questionMark.hidden = false
        answerButtonOutlet.hidden = false
        name.hidden = true
        nameField.hidden = true
        saveButtonOutlet.hidden = true
    }
    
    @IBAction func answerButton(sender: AnyObject) {
        inputAnswer = num1 * num2
        
        if (inputAnswer == Int(answerField.text!)) {
            rightOrWrong.hidden = false
            rightOrWrong.text = "CORRECT!"
            anotherButtonOutlet.hidden = false
            
            correct++
            streak.hidden = false
            streak.text = "Current streak: \(correct)"
        } else {
            
            rightOrWrong.hidden = false
            rightOrWrong.text = "WRONG!"
            anotherButtonOutlet.hidden = false
            
            correct = 0
            streak.hidden = false
            streak.text = "Current streak: \(correct)"
        }
    }
    
    @IBAction func anotherButton(sender: AnyObject) {
        answerField.text = ""
        
        num1 = Int(arc4random_uniform(10))
        num2 = Int(arc4random_uniform(10))
        problem.text = "\(num1) X \(num2)"
        inputAnswer = num1 * num2
        rightOrWrong.hidden = true
        anotherButtonOutlet.hidden = true
    }
    
    func textFieldShouldReturn(textField: UITextField) -> Bool {
        nameField.resignFirstResponder()
        answerField.resignFirstResponder()
        return true
    }
    
    override func touchesEnded(touches: Set<UITouch>, withEvent event: UIEvent?) {
        nameField.resignFirstResponder()
        answerField.resignFirstResponder()
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        nameField.delegate = self
        answerField.delegate = self
        
        let defaults = NSUserDefaults.standardUserDefaults()
        
        if let name = defaults.stringForKey("theName") {
            nameField.text = name
        }
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

