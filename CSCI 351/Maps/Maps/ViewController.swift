//
//  ViewController.swift
//  Maps
//
//  Created by Sean Tesch on 10/19/15.
//  Copyright © 2015 Sean Tesch. All rights reserved.
//

import UIKit
import MapKit

class ViewController: UIViewController {
    @IBOutlet weak var imTheMap: MKMapView!

    override func viewDidLoad() {
        super.viewDidLoad()
        let latitude: CLLocationDegrees = 46.493931
        let longitude: CLLocationDegrees = -84.363090
        let latDelta: CLLocationDegrees = 0.01
        let lonDelta: CLLocationDegrees = 0.01
        let theSpan: MKCoordinateSpan = MKCoordinateSpanMake(latDelta, lonDelta)
        
        let CASHallLocation: CLLocationCoordinate2D = CLLocationCoordinate2DMake(latitude, longitude)
        let theRegion: MKCoordinateRegion = MKCoordinateRegionMake(CASHallLocation, theSpan)
        imTheMap.setRegion(theRegion, animated: true)
        
        let CASHallAnnotation = MKPointAnnotation()
        CASHallAnnotation.coordinate = CASHallLocation
        CASHallAnnotation.title = "CAS Hall Room 210"
        CASHallAnnotation.subtitle = "Where real learning happens!"
        imTheMap.addAnnotation(CASHallAnnotation)
        
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

