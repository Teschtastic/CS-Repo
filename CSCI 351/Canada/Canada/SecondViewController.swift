//
//  SecondViewController.swift
//  Canada
//
//  Created by Sean Tesch on 9/29/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit

class SecondViewController: UIViewController {
    @IBOutlet weak var webble: UIWebView!
    
    var theURL = "http://www.saulttourism.com/"
    
    func loadWebPage() {
        let theRequestedURL = NSURL(string: theURL)
        let theRequest = NSURLRequest(URL: theRequestedURL!)
        webble.loadRequest(theRequest)
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        loadWebPage()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

