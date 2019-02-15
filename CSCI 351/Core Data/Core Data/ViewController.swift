//
//  ViewController.swift
//  Core Data
//
//  Created by Sean Tesch on 11/2/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import CoreData

class ViewController: UIViewController {
    
    @IBOutlet weak var stuId: UITextField!
    @IBOutlet weak var first: UITextField!
    @IBOutlet weak var last: UITextField!
    @IBOutlet weak var GPA: UITextField!

    @IBAction func saveButton(sender: AnyObject) {
        
        let appDel: AppDelegate = (UIApplication.sharedApplication().delegate as! AppDelegate)
        let context:NSManagedObjectContext = appDel.managedObjectContext
        
        let newStudent = NSEntityDescription.insertNewObjectForEntityForName("Student", inManagedObjectContext: context) as NSManagedObject
        
        newStudent.setValue(first.text, forKey: "firstName")
        newStudent.setValue(last.text, forKey: "lastName")
        
        let num: Int32 = Int32(stuId.text!)!
        let number = NSNumber(int: num)
        newStudent.setValue(number, forKey: "studentId")
        
        let num2: Double = Double(GPA.text!)!
        let number2 = NSNumber(double: num2)
        newStudent.setValue(number2, forKey: "gpa")
        
        do {
            try context.save()
        } catch _ {
            print("There was a problem saving to Core Data.")
        }
        
        print(newStudent)
        print("Just saved a new student")
        
        first.text = ""
        last.text = ""
        GPA.text = ""
        stuId.text = ""
    }
    
    @IBAction func searchButton(sender: AnyObject) {
        
        let appDel: AppDelegate = (UIApplication.sharedApplication().delegate as! AppDelegate)
        let context:NSManagedObjectContext = appDel.managedObjectContext
        
        let request = NSFetchRequest(entityName: "Student")
        request.returnsObjectsAsFaults = false
        request.predicate = NSPredicate(format: "studentId=%@", stuId.text!)
        let results:NSArray = try! context.executeFetchRequest(request)
        
        print("Results of Student search: ")
        if (results.count > 0) {
            let res = results[0] as! NSManagedObject
            print(res)
            first.text = res.valueForKey("firstName") as? String
            last.text = res.valueForKey("lastName") as? String
            let temp = res.valueForKey("gpa") as! NSNumber
            let temp2 = Double(temp)
            
            print("Temp2 is \(temp2)")
            GPA.text = String(format: "%.2f", temp2)
        } else {
            print("No Match")
            // Put in alert
        }
        
    }
    
    @IBAction func searchbyGPA(sender: AnyObject) {
        first.text = ""
        last.text = ""
        stuId.text = ""
        
        let appDel: AppDelegate = (UIApplication.sharedApplication().delegate as! AppDelegate)
        let context:NSManagedObjectContext = appDel.managedObjectContext
        
        let request = NSFetchRequest(entityName: "Student")
        request.returnsObjectsAsFaults = false
        request.predicate = NSPredicate(format: "gpa>=%@", GPA.text!)
        let results:NSArray = try! context.executeFetchRequest(request)
        
        print("Results of GPA search: ")
        if (results.count > 0) {
            
            print("There are \(results.count) matches.")
            var msg = ""
            
            for (var i = 0; i < results.count; i++) {
                
                let res = results[0] as! NSManagedObject
                let fn = res.valueForKey("firstName") as? String
                let ln = res.valueForKey("lastName") as? String
                let temp = res.valueForKey("gpa") as! NSNumber
                let temp2 = Double(temp)
            
                let gpa = String(format: "%.2f", temp2)
            
                msg += "\(fn!) \(ln!) has GPA of \(gpa)\n"
            }
            let alertController = UIAlertController(title: "Matches", message: msg, preferredStyle: .Alert)
            let defaultAction = UIAlertAction(title: "OK", style: .Default, handler: nil)
            alertController.addAction(defaultAction)
            presentViewController(alertController, animated: true, completion: nil)
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

